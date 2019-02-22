#include "MovementInterpolation.h"
#include "InterpolationManager.h"

MovementInterpolation::MovementInterpolation(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	initialize();
	connectUI();
}

MovementInterpolation::~MovementInterpolation()
{
}

void MovementInterpolation::connectUI() const
{
	connect(ui.openGLWidget_left, SIGNAL(initializedGL()), this, SLOT(initializeLeft()));
	connect(ui.openGLWidget_right, SIGNAL(initializedGL()), this, SLOT(initializeRight()));
	connect(ui.openGLWidget_left, SIGNAL(paintedGL()), &m_scene, SLOT(drawLeft()));
	connect(ui.openGLWidget_right, SIGNAL(paintedGL()), &m_scene, SLOT(drawRight()));
	connect(ui.doubleSpinBox_startEulerX, SIGNAL(valueChanged(double)), this, SLOT(changeStartEuler()));
	connect(ui.doubleSpinBox_startEulerY, SIGNAL(valueChanged(double)), this, SLOT(changeStartEuler()));
	connect(ui.doubleSpinBox_startEulerZ, SIGNAL(valueChanged(double)), this, SLOT(changeStartEuler()));
	connect(ui.doubleSpinBox_endEulerX, SIGNAL(valueChanged(double)), this, SLOT(changeEndEuler()));
	connect(ui.doubleSpinBox_endEulerY, SIGNAL(valueChanged(double)), this, SLOT(changeEndEuler()));
	connect(ui.doubleSpinBox_endEulerZ, SIGNAL(valueChanged(double)), this, SLOT(changeEndEuler()));
	connect(ui.doubleSpinBox_startPosX, SIGNAL(valueChanged(double)), this, SLOT(changeStartPos()));
	connect(ui.doubleSpinBox_startPosY, SIGNAL(valueChanged(double)), this, SLOT(changeStartPos()));
	connect(ui.doubleSpinBox_startPosZ, SIGNAL(valueChanged(double)), this, SLOT(changeStartPos()));
	connect(ui.doubleSpinBox_endPosX, SIGNAL(valueChanged(double)), this, SLOT(changeEndPos()));
	connect(ui.doubleSpinBox_endPosY, SIGNAL(valueChanged(double)), this, SLOT(changeEndPos()));
	connect(ui.doubleSpinBox_endPosZ, SIGNAL(valueChanged(double)), this, SLOT(changeEndPos()));
	connect(ui.doubleSpinBox_startQuatX, SIGNAL(valueChanged(double)), this, SLOT(changeStartQuat()));
	connect(ui.doubleSpinBox_startQuatY, SIGNAL(valueChanged(double)), this, SLOT(changeStartQuat()));
	connect(ui.doubleSpinBox_startQuatZ, SIGNAL(valueChanged(double)), this, SLOT(changeStartQuat()));
	connect(ui.doubleSpinBox_startQuatW, SIGNAL(valueChanged(double)), this, SLOT(changeStartQuat()));
	connect(ui.doubleSpinBox_endQuatX, SIGNAL(valueChanged(double)), this, SLOT(changeEndQuat()));
	connect(ui.doubleSpinBox_endQuatY, SIGNAL(valueChanged(double)), this, SLOT(changeEndQuat()));
	connect(ui.doubleSpinBox_endQuatZ, SIGNAL(valueChanged(double)), this, SLOT(changeEndQuat()));
	connect(ui.doubleSpinBox_endQuatW, SIGNAL(valueChanged(double)), this, SLOT(changeEndQuat()));

	connect(ui.doubleSpinBox_startEulerX, SIGNAL(valueChanged(double)), ui.openGLWidget_left, SLOT(update()));
	connect(ui.doubleSpinBox_startEulerY, SIGNAL(valueChanged(double)), ui.openGLWidget_left, SLOT(update()));
	connect(ui.doubleSpinBox_startEulerZ, SIGNAL(valueChanged(double)), ui.openGLWidget_left, SLOT(update()));
	connect(ui.doubleSpinBox_endEulerX, SIGNAL(valueChanged(double)), ui.openGLWidget_left, SLOT(update()));
	connect(ui.doubleSpinBox_endEulerY, SIGNAL(valueChanged(double)), ui.openGLWidget_left, SLOT(update()));
	connect(ui.doubleSpinBox_endEulerZ, SIGNAL(valueChanged(double)), ui.openGLWidget_left, SLOT(update()));
	connect(ui.doubleSpinBox_startPosX, SIGNAL(valueChanged(double)), ui.openGLWidget_left, SLOT(update()));
	connect(ui.doubleSpinBox_startPosY, SIGNAL(valueChanged(double)), ui.openGLWidget_left, SLOT(update()));
	connect(ui.doubleSpinBox_startPosZ, SIGNAL(valueChanged(double)), ui.openGLWidget_left, SLOT(update()));
	connect(ui.doubleSpinBox_endPosX, SIGNAL(valueChanged(double)), ui.openGLWidget_left, SLOT(update()));
	connect(ui.doubleSpinBox_endPosY, SIGNAL(valueChanged(double)), ui.openGLWidget_left, SLOT(update()));
	connect(ui.doubleSpinBox_endPosZ, SIGNAL(valueChanged(double)), ui.openGLWidget_left, SLOT(update()));
	connect(ui.doubleSpinBox_startPosX, SIGNAL(valueChanged(double)), ui.openGLWidget_right, SLOT(update()));
	connect(ui.doubleSpinBox_startPosY, SIGNAL(valueChanged(double)), ui.openGLWidget_right, SLOT(update()));
	connect(ui.doubleSpinBox_startPosZ, SIGNAL(valueChanged(double)), ui.openGLWidget_right, SLOT(update()));
	connect(ui.doubleSpinBox_endPosX, SIGNAL(valueChanged(double)), ui.openGLWidget_right, SLOT(update()));
	connect(ui.doubleSpinBox_endPosY, SIGNAL(valueChanged(double)), ui.openGLWidget_right, SLOT(update()));
	connect(ui.doubleSpinBox_endPosZ, SIGNAL(valueChanged(double)), ui.openGLWidget_right, SLOT(update()));
	connect(ui.doubleSpinBox_startQuatX, SIGNAL(valueChanged(double)), ui.openGLWidget_right, SLOT(update()));
	connect(ui.doubleSpinBox_startQuatY, SIGNAL(valueChanged(double)), ui.openGLWidget_right, SLOT(update()));
	connect(ui.doubleSpinBox_startQuatZ, SIGNAL(valueChanged(double)), ui.openGLWidget_right, SLOT(update()));
	connect(ui.doubleSpinBox_startQuatW, SIGNAL(valueChanged(double)), ui.openGLWidget_right, SLOT(update()));
	connect(ui.doubleSpinBox_endQuatX, SIGNAL(valueChanged(double)), ui.openGLWidget_right, SLOT(update()));
	connect(ui.doubleSpinBox_endQuatY, SIGNAL(valueChanged(double)), ui.openGLWidget_right, SLOT(update()));
	connect(ui.doubleSpinBox_endQuatZ, SIGNAL(valueChanged(double)), ui.openGLWidget_right, SLOT(update()));
	connect(ui.doubleSpinBox_endQuatW, SIGNAL(valueChanged(double)), ui.openGLWidget_right, SLOT(update()));
	connect(ui.doubleSpinBox_startEulerX, SIGNAL(valueChanged(double)), ui.openGLWidget_right, SLOT(update()));
	connect(ui.doubleSpinBox_startEulerY, SIGNAL(valueChanged(double)), ui.openGLWidget_right, SLOT(update()));
	connect(ui.doubleSpinBox_startEulerZ, SIGNAL(valueChanged(double)), ui.openGLWidget_right, SLOT(update()));
	connect(ui.doubleSpinBox_endEulerX, SIGNAL(valueChanged(double)), ui.openGLWidget_right, SLOT(update()));
	connect(ui.doubleSpinBox_endEulerY, SIGNAL(valueChanged(double)), ui.openGLWidget_right, SLOT(update()));
	connect(ui.doubleSpinBox_endEulerZ, SIGNAL(valueChanged(double)), ui.openGLWidget_right, SLOT(update()));
	connect(ui.doubleSpinBox_startQuatX, SIGNAL(valueChanged(double)), ui.openGLWidget_left, SLOT(update()));
	connect(ui.doubleSpinBox_startQuatY, SIGNAL(valueChanged(double)), ui.openGLWidget_left, SLOT(update()));
	connect(ui.doubleSpinBox_startQuatZ, SIGNAL(valueChanged(double)), ui.openGLWidget_left, SLOT(update()));
	connect(ui.doubleSpinBox_startQuatW, SIGNAL(valueChanged(double)), ui.openGLWidget_left, SLOT(update()));
	connect(ui.doubleSpinBox_endQuatX, SIGNAL(valueChanged(double)), ui.openGLWidget_left, SLOT(update()));
	connect(ui.doubleSpinBox_endQuatY, SIGNAL(valueChanged(double)), ui.openGLWidget_left, SLOT(update()));
	connect(ui.doubleSpinBox_endQuatZ, SIGNAL(valueChanged(double)), ui.openGLWidget_left, SLOT(update()));
	connect(ui.doubleSpinBox_endQuatW, SIGNAL(valueChanged(double)), ui.openGLWidget_left, SLOT(update()));

	connect(ui.pushButton_Start, SIGNAL(clicked()), this, SLOT(startSimulation()));
	connect(ui.pushButton_Reset, SIGNAL(clicked()), this, SLOT(resetSimulation()));
	connect(ui.pushButton_Reset, SIGNAL(clicked()), &m_scene, SLOT(reset()));
	connect(ui.spinBox_time, SIGNAL(valueChanged(int)), &m_scene, SLOT(changeAnimationTime(int)));
	connect(m_scene.getComputationTimer(), SIGNAL(timeout()), ui.openGLWidget_left, SLOT(update()));
	connect(m_scene.getComputationTimer(), SIGNAL(timeout()), ui.openGLWidget_right, SLOT(update()));
	//connect(m_scene.getDrawTimer(), SIGNAL(timeout()), ui.openGLWidget_left, SLOT(update()));
	//connect(m_scene.getDrawTimer(), SIGNAL(timeout()), ui.openGLWidget_right, SLOT(update()));
	connect(ui.checkBox_steps, SIGNAL(stateChanged(int)), &m_scene, SLOT(changeDrawStepsState(int)));
}

void MovementInterpolation::initialize()
{
	ui.openGLWidget_left->setRenderer(m_scene.getLeftRenderer());
	ui.openGLWidget_right->setRenderer(m_scene.getRightRenderer());
	const bool slerp = (ui.comboBox_s_lerp->currentText() == "slerp");
	m_scene.initialize(ui.spinBox_time->value(), ui.spinBox_frames->value(), slerp, ui.checkBox_steps->isChecked());
}

void MovementInterpolation::setStartEulerSignalState(bool state)
{
	ui.doubleSpinBox_startEulerX->blockSignals(state);
	ui.doubleSpinBox_startEulerY->blockSignals(state);
	ui.doubleSpinBox_startEulerZ->blockSignals(state);
}

void MovementInterpolation::setStartQuatSignalState(bool state)
{
	ui.doubleSpinBox_startQuatX->blockSignals(state);
	ui.doubleSpinBox_startQuatY->blockSignals(state);
	ui.doubleSpinBox_startQuatZ->blockSignals(state);
	ui.doubleSpinBox_startQuatW->blockSignals(state);
}

void MovementInterpolation::setEndEulerSignalState(bool state)
{
	ui.doubleSpinBox_endEulerX->blockSignals(state);
	ui.doubleSpinBox_endEulerY->blockSignals(state);
	ui.doubleSpinBox_endEulerZ->blockSignals(state);
}

void MovementInterpolation::setEndQuatSignalState(bool state)
{
	ui.doubleSpinBox_endQuatX->blockSignals(state);
	ui.doubleSpinBox_endQuatY->blockSignals(state);
	ui.doubleSpinBox_endQuatZ->blockSignals(state);
	ui.doubleSpinBox_endQuatW->blockSignals(state);
}

void MovementInterpolation::initializeLeft()
{
	m_scene.initializeLeft();
}

void MovementInterpolation::initializeRight()
{
	m_scene.initializeRight();
}

void MovementInterpolation::changeStartEuler()
{
	m_scene.updateStartEuler(QVector3D(ui.doubleSpinBox_startEulerX->value(), ui.doubleSpinBox_startEulerY->value(), ui.doubleSpinBox_startEulerZ->value()));
	const QQuaternion q = InterpolationManager::toQuaternion(ui.doubleSpinBox_startEulerZ->value(),
		ui.doubleSpinBox_startEulerY->value(),
		ui.doubleSpinBox_startEulerX->value());
	m_scene.updateStartQuat(q);
	setStartQuatSignalState(true);
	ui.doubleSpinBox_startQuatX->setValue(q.x());
	ui.doubleSpinBox_startQuatY->setValue(q.y());
	ui.doubleSpinBox_startQuatZ->setValue(q.z());
	ui.doubleSpinBox_startQuatW->setValue(q.scalar());
	setStartQuatSignalState(false);
}

void MovementInterpolation::changeStartPos()
{
	m_scene.updateStartPos(QVector3D(ui.doubleSpinBox_startPosX->value(), ui.doubleSpinBox_startPosY->value(), ui.doubleSpinBox_startPosZ->value()));
}

void MovementInterpolation::changeStartQuat()
{
	const QQuaternion q = QQuaternion(ui.doubleSpinBox_startQuatW->value(), ui.doubleSpinBox_startQuatX->value(),
	                                   ui.doubleSpinBox_startQuatY->value(), ui.doubleSpinBox_startQuatZ->value()).normalized();
	m_scene.updateStartQuat(q);
	const QVector3D angles = InterpolationManager::toEulerAngle(q);
	m_scene.updateStartEuler(angles);
	setStartEulerSignalState(true);
	//setStartQuatSignalState(true);
	ui.doubleSpinBox_startEulerX->setValue(angles.x());
	ui.doubleSpinBox_startEulerY->setValue(angles.y());
	ui.doubleSpinBox_startEulerZ->setValue(angles.z());
	/*ui.doubleSpinBox_startQuatX->setValue(q.x());
	ui.doubleSpinBox_startQuatY->setValue(q.y());
	ui.doubleSpinBox_startQuatZ->setValue(q.z());
	ui.doubleSpinBox_startQuatW->setValue(q.scalar());*/
	setStartEulerSignalState(false);
	//setStartQuatSignalState(false);
}

void MovementInterpolation::changeEndEuler()
{
	m_scene.updateEndEuler(QVector3D(ui.doubleSpinBox_endEulerX->value(), ui.doubleSpinBox_endEulerY->value(), ui.doubleSpinBox_endEulerZ->value()));
	const QQuaternion q = InterpolationManager::toQuaternion(ui.doubleSpinBox_endEulerZ->value(),
		ui.doubleSpinBox_endEulerY->value(),
		ui.doubleSpinBox_endEulerX->value());
	m_scene.updateEndQuat(q);
	setEndQuatSignalState(true);
	ui.doubleSpinBox_endQuatX->setValue(q.x());
	ui.doubleSpinBox_endQuatY->setValue(q.y());
	ui.doubleSpinBox_endQuatZ->setValue(q.z());
	ui.doubleSpinBox_endQuatW->setValue(q.scalar());
	setEndQuatSignalState(false);
}

void MovementInterpolation::changeEndPos()
{
	m_scene.updateEndPos(QVector3D(ui.doubleSpinBox_endPosX->value(), ui.doubleSpinBox_endPosY->value(), ui.doubleSpinBox_endPosZ->value()));
}

void MovementInterpolation::changeEndQuat()
{
	const QQuaternion q = QQuaternion(ui.doubleSpinBox_endQuatW->value(), ui.doubleSpinBox_endQuatX->value(),
	                                   ui.doubleSpinBox_endQuatY->value(), ui.doubleSpinBox_endQuatZ->value()).normalized();
	m_scene.updateEndQuat(q);
	const QVector3D angles = InterpolationManager::toEulerAngle(q);
	m_scene.updateEndEuler(angles);
	setEndEulerSignalState(true);
	/*setEndQuatSignalState(true);*/
	ui.doubleSpinBox_endEulerX->setValue(angles.x());
	ui.doubleSpinBox_endEulerY->setValue(angles.y());
	ui.doubleSpinBox_endEulerZ->setValue(angles.z());
	/*ui.doubleSpinBox_endQuatX->setValue(q.x());
	ui.doubleSpinBox_endQuatY->setValue(q.y());
	ui.doubleSpinBox_endQuatZ->setValue(q.z());
	ui.doubleSpinBox_endQuatW->setValue(q.scalar());*/
	setEndEulerSignalState(false);
	/*setEndQuatSignalState(false);*/
}

void MovementInterpolation::startSimulation()
{
	const QQuaternion start = m_scene.getInterpolationData().startQuaternion.normalized();
	const QQuaternion end = m_scene.getInterpolationData().endQuaternion.normalized();
	setStartQuatSignalState(true);
	ui.doubleSpinBox_startQuatX->setValue(start.x());
	ui.doubleSpinBox_startQuatY->setValue(start.y());
	ui.doubleSpinBox_startQuatZ->setValue(start.z());
	ui.doubleSpinBox_startQuatW->setValue(start.scalar());
	setStartQuatSignalState(false);
	setEndQuatSignalState(true);
	ui.doubleSpinBox_endQuatX->setValue(end.x());
	ui.doubleSpinBox_endQuatY->setValue(end.y());
	ui.doubleSpinBox_endQuatZ->setValue(end.z());
	ui.doubleSpinBox_endQuatW->setValue(end.scalar());
	setEndQuatSignalState(false);
	const bool slerp = (ui.comboBox_s_lerp->currentText() == "slerp");
	m_scene.initialize(ui.spinBox_time->value(), ui.spinBox_frames->value(), slerp, ui.checkBox_steps->isChecked());
	m_scene.startSimulation();
}

void MovementInterpolation::resetSimulation()
{
	setStartQuatSignalState(true);
	ui.doubleSpinBox_startQuatX->setValue(0);
	ui.doubleSpinBox_startQuatY->setValue(0);
	ui.doubleSpinBox_startQuatZ->setValue(0);
	ui.doubleSpinBox_startQuatW->setValue(1);
	setStartQuatSignalState(false);
	setEndQuatSignalState(true);
	ui.doubleSpinBox_endQuatX->setValue(0);
	ui.doubleSpinBox_endQuatY->setValue(0);
	ui.doubleSpinBox_endQuatZ->setValue(0);
	ui.doubleSpinBox_endQuatW->setValue(1);
	setEndQuatSignalState(false);
	setStartEulerSignalState(true);
	ui.doubleSpinBox_startEulerX->setValue(0);
	ui.doubleSpinBox_startEulerY->setValue(0);
	ui.doubleSpinBox_startEulerZ->setValue(0);
	setStartEulerSignalState(false);
	setEndEulerSignalState(true);
	ui.doubleSpinBox_endEulerX->setValue(0);
	ui.doubleSpinBox_endEulerY->setValue(0);
	ui.doubleSpinBox_endEulerZ->setValue(0);
	setEndEulerSignalState(false);
	ui.doubleSpinBox_startPosX->setValue(0);
	ui.doubleSpinBox_startPosY->setValue(0);
	ui.doubleSpinBox_startPosZ->setValue(0);
	ui.doubleSpinBox_endPosX->setValue(0);
	ui.doubleSpinBox_endPosY->setValue(0);
	ui.doubleSpinBox_endPosZ->setValue(0);
}

