#pragma once
#include "Renderer.h"
#include <qtimer.h>
#include "Cross.h"
#include "InterpolationData.h"
#include <qelapsedtimer.h>

struct ShaderData;

class Scene : public QObject
{
	Q_OBJECT
public:
	Scene();
	~Scene();

	void connect() const;
	//const QTimer* getComputationsTimer() const;
	//const QTimer* getDrawTimer() const;
	Renderer *getLeftRenderer();
	Renderer *getRightRenderer();
	void initializeLeft();
	void initializeRight();
	void initialize(int animationTime, int stepsCount, bool slerp, bool showSteps);
	void updateStartEuler(const QVector3D &euler);
	void updateStartPos(const QVector3D &pos);
	void updateStartQuat(const QQuaternion &q);
	void updateEndEuler(const QVector3D &euler);
	void updateEndPos(const QVector3D &pos);
	void updateEndQuat(const QQuaternion &q);
	const InterpolationData& getInterpolationData() const;
	void startSimulation();
	QTimer* getComputationTimer() const;
	//QTimer* getDrawTimer() const;

private:
	Renderer m_leftRenderer;
	Renderer m_rightRenderer;
	int m_animationTime;
	int m_stepsCount;
	bool m_showSteps;
	bool m_slerp;
	float m_radius;
	float m_length;
	InterpolationData m_data;
	int m_drawStep;
	int m_updateStep;
	QTimer *m_timerComputations;
	//QTimer *m_timerDraw;
	QElapsedTimer m_timerElapsed;
	std::shared_ptr<Cross> m_leftStartCross;
	std::shared_ptr<Cross> m_leftEndCross;
	std::shared_ptr<Cross> m_rightStartCross;
	std::shared_ptr<Cross> m_rightEndCross;
	std::shared_ptr<Cross> m_leftCross;
	std::shared_ptr<Cross> m_rightCross;
	std::vector<int> m_stepsIds;

	void updateLogic(int time);
	void addStepsMeshes();
	void setPosRotation(std::shared_ptr<Cross> &cross, const QQuaternion &q, const QVector3D &pos);
	void setPosRotation(std::shared_ptr<Cross> &cross, const QVector3D &rotation, const QVector3D &pos);
	void checkAngles();
	void deleteStepsMeshes();
	/*void setLeftStartCross();
	void setRightStartCross();
	void setLeftEndCross();
	void setRightEndCross();*/

private slots:
	void initializeProgram(QOpenGLShaderProgram *program, const ShaderData &shaderData) const;
	//void startComputations();
	void drawLeft();
	void drawRight();
	void changeAnimationTime(int value);
	void stopSimulation();
	void update();
	void draw();
	void changeDrawStepsState(int state);
	void reset();

signals:
	void updated();
	void animationFinished();
};
