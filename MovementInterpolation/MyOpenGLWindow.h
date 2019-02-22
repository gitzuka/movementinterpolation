#pragma once
#ifndef MYOPENGLWINDOW_H
#define MYOPENGLWINDOW_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions_4_5_Core>
#include <QDateTime>

class Renderer;

class MyOpenGLWindow : public QOpenGLWidget, protected QOpenGLFunctions_4_5_Core
{
	Q_OBJECT
public:
	explicit MyOpenGLWindow(QWidget *parent = 0);
	~MyOpenGLWindow();

	void setRenderer(Renderer *renderer);

protected:
	void initializeGL();
	void paintGL();
	void resizeGL(int width, int height);

	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void keyPressEvent(QKeyEvent *event);

private:
	Renderer *m_renderer;

signals:
	void initializedGL();
	void paintedGL();
};

#endif //GLANIMATIONWINDOW_H