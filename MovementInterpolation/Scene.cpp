#include "Scene.h"
#include "ShaderData.h"
#include "InterpolationManager.h"

Scene::Scene() : m_radius(0.01f), m_length(0.2f), m_drawStep(30), m_updateStep(50), m_timerComputations(new QTimer(this)),
	m_timerElapsed(QElapsedTimer()) //m_timerDraw(new QTimer(this)), 
{
	Scene::connect();
}

Scene::~Scene()
{
	delete m_timerComputations;
}

void Scene::initializeLeft()
{
	const ShaderData shaderData;
	initializeProgram(m_leftRenderer.getGraphics(0)->getProgram(), shaderData);
	m_leftStartCross = std::make_shared<Cross>(GL_TRIANGLES, m_radius, m_length);
	m_leftEndCross = std::make_shared<Cross>(GL_TRIANGLES, m_radius, m_length);
	m_leftCross = std::make_shared<Cross>(GL_TRIANGLES, m_radius, m_length);
	m_leftRenderer.getGraphics(0)->addMesh(m_leftStartCross, QOpenGLBuffer::StaticDraw);
	m_leftRenderer.getGraphics(0)->initBuffer(m_leftStartCross->getId(), QOpenGLBuffer::StaticDraw);
	m_leftRenderer.getGraphics(0)->addMesh(m_leftEndCross, QOpenGLBuffer::StaticDraw);
	m_leftRenderer.getGraphics(0)->initBuffer(m_leftEndCross->getId(), QOpenGLBuffer::StaticDraw);
	m_leftRenderer.getGraphics(0)->addMesh(m_leftCross, QOpenGLBuffer::StaticDraw);
	m_leftRenderer.getGraphics(0)->initBuffer(m_leftCross->getId(), QOpenGLBuffer::StaticDraw);
}

void Scene::initializeRight()
{
	const ShaderData shaderData;
	initializeProgram(m_rightRenderer.getGraphics(0)->getProgram(), shaderData);
	m_rightStartCross = std::make_shared<Cross>(GL_TRIANGLES, m_radius, m_length);
	m_rightEndCross = std::make_shared<Cross>(GL_TRIANGLES, m_radius, m_length);
	m_rightCross = std::make_shared<Cross>(GL_TRIANGLES, m_radius, m_length);
	m_rightRenderer.getGraphics(0)->addMesh(m_rightStartCross, QOpenGLBuffer::StaticDraw);
	m_rightRenderer.getGraphics(0)->initBuffer(m_rightStartCross->getId(), QOpenGLBuffer::StaticDraw);
	m_rightRenderer.getGraphics(0)->addMesh(m_rightEndCross, QOpenGLBuffer::StaticDraw);
	m_rightRenderer.getGraphics(0)->initBuffer(m_rightEndCross->getId(), QOpenGLBuffer::StaticDraw);
	m_rightRenderer.getGraphics(0)->addMesh(m_rightCross, QOpenGLBuffer::StaticDraw);
	m_rightRenderer.getGraphics(0)->initBuffer(m_rightCross->getId(), QOpenGLBuffer::StaticDraw);
}

void Scene::update()
{
	int k = m_timerElapsed.elapsed();
	int t = m_animationTime - m_timerElapsed.elapsed();
	if (t > 0)
	{
		updateLogic(t);
	}
	else
	{
		updateLogic(1);
		emit animationFinished();
	}
	emit updated();
	//while (int t = m_animationTime - m_timerElapsed.elapsed() > 0)
	//{
		//updateLogic(t);
		//drawLeft();
		//drawRight();
		//emit updated();
	//}
}

void Scene::draw()
{
	drawLeft();
	drawRight();
}

void Scene::changeDrawStepsState(int state)
{
	m_drawStep = state;
	for (std::_Simple_types<int>::value_type& m_stepsId : m_stepsIds)
	{
		m_rightRenderer.getGraphics(0)->setDrawState(m_drawStep, m_stepsId);
		m_leftRenderer.getGraphics(0)->setDrawState(m_drawStep, m_stepsId);
	}
}

void Scene::reset()
{
	m_leftRenderer.resetCamera();
	m_rightRenderer.resetCamera();
	deleteStepsMeshes();
}

void Scene::updateLogic(int time)
{
	//double t = (m_animationTime - m_timerElapsed.elapsed()) / static_cast<double>(m_animationTime);
	double t = time / static_cast<double>(m_animationTime);
	t = 1 - t;
	QVector3D pos = InterpolationManager::lerp(m_data.startPos, m_data.endPos, t);
	QVector3D angle = InterpolationManager::lerp(m_data.startEuler, m_data.endEuler, t);
	QQuaternion q;
	if (m_slerp)
		q = InterpolationManager::slerp(m_data.startQuaternion, m_data.endQuaternion, t);
	else
		q = InterpolationManager::lerp(m_data.startQuaternion, m_data.endQuaternion, t).normalized();
	setPosRotation(m_leftCross, angle, pos);
	setPosRotation(m_rightCross, q, pos);
	/*const QMatrix4x4 rot = Camera::createRotationZ(InterpolationManager::convertToRadians(angle.z()))
		* Camera::createRotationY(InterpolationManager::convertToRadians(angle.y()))
		* Camera::createRotationX(InterpolationManager::convertToRadians(angle.x()));*/
		//m_leftCross->setModelMatrix(Camera::createTranslation(pos) * rot);
		//m_rightCross->setModelMatrix(Camera::createTranslation(pos) * QMatrix4x4(q.toRotationMatrix()));
}

void Scene::addStepsMeshes()
{
	for (int i = 1; i < m_stepsCount; ++i)
	{
		std::shared_ptr<Cross> crossLeft = std::make_shared<Cross>(GL_TRIANGLES, m_radius, m_length);
		std::shared_ptr<Cross> crossRight = std::make_shared<Cross>(GL_TRIANGLES, m_radius, m_length);
		crossLeft->setDrawState(m_showSteps);
		crossRight->setDrawState(m_showSteps);
		m_stepsIds.push_back(crossLeft->getId());
		m_stepsIds.push_back(crossRight->getId());
		m_leftRenderer.getGraphics(0)->addMesh(crossLeft, QOpenGLBuffer::StaticDraw);
		m_leftRenderer.getGraphics(0)->initBuffer(crossLeft->getId(), QOpenGLBuffer::StaticDraw);
		m_rightRenderer.getGraphics(0)->addMesh(crossRight, QOpenGLBuffer::StaticDraw);
		m_rightRenderer.getGraphics(0)->initBuffer(crossRight->getId(), QOpenGLBuffer::StaticDraw);
		const double t = i / static_cast<double>(m_stepsCount);
		auto rot = InterpolationManager::lerp(m_data.startEuler, m_data.endEuler, t);
		auto pos = InterpolationManager::lerp(m_data.startPos, m_data.endPos, t);
		setPosRotation(crossLeft, rot, pos);
		QQuaternion q;
		if (m_slerp)
			q = InterpolationManager::slerp(m_data.startQuaternion, m_data.endQuaternion, t);
		else
			q = InterpolationManager::lerp(m_data.startQuaternion, m_data.endQuaternion, t).normalized();
		setPosRotation(crossRight, q, pos);
	}
}

void Scene::setPosRotation(std::shared_ptr<Cross> &cross, const QQuaternion &q, const QVector3D &pos)
{
	cross->setModelMatrix(Camera::createTranslation(pos) * QMatrix4x4(q.toRotationMatrix()));
}

void Scene::setPosRotation(std::shared_ptr<Cross> &cross, const QVector3D& rotation, const QVector3D& pos)
{
	const QMatrix4x4 rot = Camera::createRotationZ(InterpolationManager::convertToRadians(rotation.z()))
		* Camera::createRotationY(InterpolationManager::convertToRadians(rotation.y()))
		* Camera::createRotationX(InterpolationManager::convertToRadians(rotation.x()));
	cross->setModelMatrix(Camera::createTranslation(pos) * rot);
}

void Scene::checkAngles()
{
	const float angleX1 = m_data.startEuler.x();
	const float angleX2 = m_data.endEuler.x();
	if (abs(angleX1 - angleX2) > 180)
	{
		angleX1 > angleX2 ? m_data.startEuler.setX(angleX1 - 360) : m_data.endEuler.setX(angleX2 - 360);
	}

	const float angleY1 = m_data.startEuler.y();
	const float angleY2 = m_data.endEuler.y();
	if (abs(angleY1 - angleY2) > 180)
	{
		angleY1 > angleY2 ? m_data.startEuler.setY(angleY1 - 360) : m_data.endEuler.setY(angleY2 - 360);
	}

	const float angleZ1 = m_data.startEuler.z();
	const float angleZ2 = m_data.endEuler.z();
	if (abs(angleZ1 - angleZ2) > 180)
	{
		angleZ1 > angleZ2 ? m_data.startEuler.setZ(angleZ1 - 360) : m_data.endEuler.setZ(angleZ2 - 360);
	}

	m_data.startQuaternion.normalize();// q0.normalize();
	m_data.endQuaternion.normalize();

	float dot = QQuaternion::dotProduct(m_data.startQuaternion, m_data.endQuaternion);
	//check if the path is shorter to -q than to q
	if (dot < 0.0f)
	{
		m_data.endQuaternion = -m_data.endQuaternion;
		dot = -dot;
	}
}

void Scene::deleteStepsMeshes()
{
	for (std::_Simple_types<int>::value_type& m_stepsId : m_stepsIds)
	{
		m_rightRenderer.getGraphics(0)->deleteMesh(m_stepsId);
		m_leftRenderer.getGraphics(0)->deleteMesh(m_stepsId);
	}
	m_stepsIds.clear();
}

void Scene::initializeProgram(QOpenGLShaderProgram *program, const ShaderData &shaderData) const
{
	program->bind();
	program->setUniformValue("lightPos", shaderData.lightPos);
	program->setUniformValue("lightColor", shaderData.lightColor);
	program->setUniformValue("objectColor", shaderData.objectColor);
	program->setUniformValue("light.intensity", shaderData.lightIntensity);
	program->setUniformValue("ambient", shaderData.materialKa);
	program->setUniformValue("diffuse", shaderData.materialKd);
	program->setUniformValue("specular", shaderData.materialKs);
	program->setUniformValue("shininess", shaderData.materialShininess);
	program->release();
}

void Scene::drawLeft()
{
	m_leftRenderer.draw();
}

void Scene::drawRight()
{
	m_rightRenderer.draw();
}

void Scene::changeAnimationTime(int value)
{
	m_animationTime = value * 1000; //convert to ms
}

void Scene::stopSimulation()
{
	//m_timerDraw->stop();
	m_timerComputations->stop();
}

void Scene::updateStartEuler(const QVector3D& euler)
{
	m_data.startEuler = euler;
	setPosRotation(m_leftStartCross, m_data.startEuler, m_data.startPos);
	setPosRotation(m_leftCross, m_data.startEuler, m_data.startPos);
}

void Scene::updateStartPos(const QVector3D& pos)
{
	m_data.startPos = pos;
	setPosRotation(m_leftStartCross, m_data.startEuler, m_data.startPos);
	setPosRotation(m_rightStartCross, m_data.startQuaternion, m_data.startPos);
	setPosRotation(m_leftCross, m_data.startQuaternion, m_data.startPos);
	setPosRotation(m_rightCross, m_data.startQuaternion, m_data.startPos);
}

void Scene::updateStartQuat(const QQuaternion& q)
{
	QQuaternion a = q.normalized();
	m_data.startQuaternion = q;
	setPosRotation(m_rightStartCross, m_data.startQuaternion, m_data.startPos);
	setPosRotation(m_rightCross, m_data.startQuaternion, m_data.startPos);
}

void Scene::updateEndEuler(const QVector3D& euler)
{
	m_data.endEuler = euler;
	setPosRotation(m_leftEndCross, m_data.endEuler, m_data.endPos);
}

void Scene::updateEndPos(const QVector3D& pos)
{
	m_data.endPos = pos;
	setPosRotation(m_leftEndCross, m_data.endEuler, m_data.endPos);
	setPosRotation(m_rightEndCross, m_data.endQuaternion, m_data.endPos);
}

void Scene::updateEndQuat(const QQuaternion& q)
{
	m_data.endQuaternion = q;
	setPosRotation(m_rightEndCross, m_data.endQuaternion, m_data.endPos);
}

const InterpolationData& Scene::getInterpolationData() const
{
	return m_data;
}

void Scene::initialize(int animationTime, int stepsCount, bool slerp, bool showSteps)
{
	m_animationTime = animationTime * 1000;
	m_stepsCount = stepsCount;
	m_slerp = slerp;
	m_showSteps = showSteps;
}

void Scene::connect() const
{
	QObject::connect(m_timerComputations, SIGNAL(timeout()), this, SLOT(update()));
	QObject::connect(this, SIGNAL(animationFinished()), this, SLOT(stopSimulation()));
	QObject::connect(this, SIGNAL(updated()), this, SLOT(drawLeft()));
	QObject::connect(this, SIGNAL(updated()), this, SLOT(drawRight()));
	//QObject::connect(m_timerDraw, SIGNAL(timeout()), this, SLOT(drawLeft()));
	//QObject::connect(m_timerDraw, SIGNAL(timeout()), this, SLOT(drawRight()));
}

Renderer* Scene::getLeftRenderer()
{
	return &m_leftRenderer;
}

Renderer* Scene::getRightRenderer()
{
	return &m_rightRenderer;
}

void Scene::startSimulation()
{
	checkAngles();
	deleteStepsMeshes();
	addStepsMeshes();
	m_timerElapsed = QElapsedTimer();
	m_timerElapsed.start();
	m_timerComputations->start(m_updateStep);
	
	//m_timerDraw->start(m_drawStep);
	//update();
}

QTimer* Scene::getComputationTimer() const
{
	return m_timerComputations;
}

//QTimer* Scene::getDrawTimer() const
//{
//	return m_timerDraw;
//}
