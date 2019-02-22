#pragma once
#include "Mesh.h"

class Cylinder : public Mesh
{
public:
	Cylinder(QOpenGLBuffer::UsagePattern drawPattern, GLenum drawMode, float radius, float height, const QVector3D &color);
	//Cylinder(GLenum drawMode, int index, const MillingMaterialData &data);
	~Cylinder();

	void generateVertices() override;
	void setBasePositionZ(float angle);
	void setBasePositionX(float angle);
	void generateIndices() override;
	QOpenGLBuffer::UsagePattern getDrawPattern() const;

private:
	float m_radius;
	float m_height;
	QOpenGLBuffer::UsagePattern m_drawPattern;
	QVector3D m_color;
};
