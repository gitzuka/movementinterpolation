#include "Cross.h"

Cross::Cross(GLenum drawMode, float radius, float length) : Mesh(drawMode), m_radius(radius), m_length(length)
{
	Cross::generateVertices();
}

void Cross::generateVertices()
{

	Cylinder x = Cylinder(QOpenGLBuffer::UsagePattern::StaticDraw, GL_TRIANGLES, m_radius, m_length, QVector3D(1, 0, 0));
	x.setBasePositionZ(-90.0f);
	Cylinder y = Cylinder(QOpenGLBuffer::UsagePattern::StaticDraw, GL_TRIANGLES, m_radius, m_length, QVector3D(0, 1, 0));
	Cylinder z = Cylinder(QOpenGLBuffer::UsagePattern::StaticDraw, GL_TRIANGLES, m_radius, m_length, QVector3D(0, 0, 1));
	z.setBasePositionX(-90.0f);
	/*int vX = x.getVertices().size();
	int vY = y.getVertices().size();
	int vZ = z.getVertices().size();*/
	m_vertices = x.getVertices();
	m_indices = x.getIndices();
	int indCount = m_vertices.size();
	for (unsigned int i : y.getIndices())
	{
		m_indices.push_back(i + indCount);
	}
	m_vertices.insert(m_vertices.end(), y.getVertices().begin(), y.getVertices().end());
	indCount = m_vertices.size();
	for (unsigned int i : z.getIndices())
	{
		m_indices.push_back(i + indCount);
	}
	m_vertices.insert(m_vertices.end(), z.getVertices().begin(), z.getVertices().end());
	
	
}

void Cross::generateIndices()
{
}
