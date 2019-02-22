#pragma once
#include <QVector3D>

struct ShaderData
{
	QVector3D lightPos = QVector3D(10.0f, 10.0f, 0.0f);
	QVector3D lightColor = QVector3D(1.0f, 1.0f, 1.0f);
	QVector3D objectColor = QVector3D(1.0f, 0.0f, 1.0f);
	QVector3D lightIntensity = QVector3D(0.1f, 1.0f, 1.0f);
	QVector3D materialKa = QVector3D(0.05f, 0.2f, 0.05f);
	QVector3D materialKd = QVector3D(0.3f, 0.5f, 0.3f);
	QVector3D materialKs = QVector3D(0.6f, 0.6f, 0.6f);
	float materialShininess = 50.0f;
};
