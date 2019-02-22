#include "MyOpenGLWindow.h"
#include <QtGui>
#include "Graphics.h"
#include "Renderer.h"

MyOpenGLWindow::MyOpenGLWindow(QWidget* parent) : m_renderer(nullptr)
{
}

MyOpenGLWindow::~MyOpenGLWindow()
{
	makeCurrent();
}

void MyOpenGLWindow::setRenderer(Renderer* renderer)
{
	m_renderer = renderer;
}


void MyOpenGLWindow::initializeGL()
{
	//this->setCursor(Qt::BlankCursor);
	initializeOpenGLFunctions();
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	auto *program = new QOpenGLShaderProgram();
	program->addShaderFromSourceFile(QOpenGLShader::Vertex, "C:/Users/Andrzej/Documents/Visual Studio 2015/Projects/MovementInterpolation/MovementInterpolation/puma.vert");
	program->addShaderFromSourceFile(QOpenGLShader::Fragment, "C:/Users/Andrzej/Documents/Visual Studio 2015/Projects/MovementInterpolation/MovementInterpolation/puma.frag");
	program->link();
	std::shared_ptr<Graphics> millingGraphics = std::make_shared<Graphics>(program);
	m_renderer->addGraphicComponent(millingGraphics);

	emit initializedGL();
}

void MyOpenGLWindow::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	emit paintedGL();
}

void MyOpenGLWindow::resizeGL(int width, int height)
{
	glViewport(0, 0, width, height);
	m_renderer->getCamera().m_projectionMatrix = Camera::createProjection(width, height);
	m_renderer->getCamera().m_projView = m_renderer->getCamera().m_projectionMatrix * m_renderer->getCamera().m_viewMatrix;
}

void MyOpenGLWindow::mousePressEvent(QMouseEvent* event)
{
	m_renderer->getCamera().m_mousePos = event->pos();
	this->update();
}

void MyOpenGLWindow::mouseMoveEvent(QMouseEvent* event)
{
	float dx = event->x() - m_renderer->getCamera().m_mousePos.x();
	float dy = event->y() - m_renderer->getCamera().m_mousePos.y();
	m_renderer->getCamera().m_mousePos = event->pos();
	if (event->buttons() & Qt::RightButton)
	{
		m_renderer->getCamera().mouseMoved(dx, dy);
	}
	this->update();
}

void MyOpenGLWindow::keyPressEvent(QKeyEvent *event)
{
	m_renderer->getCamera().keyPressed(event->key());
	this->update();
}
