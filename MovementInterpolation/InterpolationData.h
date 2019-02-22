#pragma once
#include <QQuaternion>

struct InterpolationData
{
	QVector3D startPos;
	QVector3D endPos;
	QVector3D startEuler;
	QVector3D endEuler;
	/*float startPosX{};
	float startPosY{};
	float startPosZ{};
	float endPosX{};
	float endPosY{};
	float endPosZ{};
	int startAngleX{};
	int startAngleY{};
	int startAngleZ{};
	int endAngleX{};
	int endAngleY{};
	int endAngleZ{};*/
	QQuaternion startQuaternion;
	QQuaternion endQuaternion;
};
