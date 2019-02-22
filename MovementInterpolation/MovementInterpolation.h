#ifndef MOVEMENTINTERPOLATION_H
#define MOVEMENTINTERPOLATION_H

#include <QtWidgets/QMainWindow>
#include "ui_movementinterpolation.h"
#include "Scene.h"

class MovementInterpolation : public QMainWindow
{
	Q_OBJECT

public:
	MovementInterpolation(QWidget *parent = 0);
	~MovementInterpolation();

private:
	Ui::MovementInterpolationClass ui;
	Scene m_scene;

	void connectUI() const;
	void initialize();
	void setStartEulerSignalState(bool state);
	void setStartQuatSignalState(bool state);
	void setEndEulerSignalState(bool state);
	void setEndQuatSignalState(bool state);

private slots:
	void initializeLeft();
	void initializeRight();
	void changeStartEuler();
	void changeStartPos();
	void changeStartQuat();
	void changeEndEuler();
	void changeEndPos();
	void changeEndQuat();
	void startSimulation();
	void resetSimulation();
};

#endif // MOVEMENTINTERPOLATION_H
