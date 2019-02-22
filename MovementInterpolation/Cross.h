#pragma once
#include "Cylinder.h"

class Cross : public Mesh
{
public:
	Cross(GLenum drawMode, float radius, float length);
	void generateVertices() override;
	void generateIndices() override;

private:
	float m_radius;
	float m_length;
};
