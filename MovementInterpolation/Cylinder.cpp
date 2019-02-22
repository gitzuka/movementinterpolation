#include "Cylinder.h"
#include <qmath.h>
#include "Camera.h"
#include "InterpolationManager.h"

Cylinder::Cylinder(QOpenGLBuffer::UsagePattern drawPattern, GLenum drawMode, float radius, float height, const QVector3D &color)
	: Mesh(drawMode), m_radius(radius), m_height(height), m_drawPattern(drawPattern), m_color(color)
{
	Cylinder::generateVertices();
	Cylinder::generateIndices();
}

Cylinder::~Cylinder()
= default;

void Cylinder::generateVertices()
{
	const int verticesCount = 18;
	const float theta = 2 * M_PI / verticesCount;
	for (int i = 0; i < verticesCount; ++i)
	{
		const float tx = static_cast<float>(i) / verticesCount;
		float angle = theta * i;
		m_vertices.emplace_back(QVector3D(m_radius * cos(theta * i), 0, m_radius * sin(theta * i)), QVector3D(cos(theta * i), 0, sin(theta * i)), m_color, QVector2D(tx, 1));
		m_vertices.emplace_back(QVector3D(m_radius * cos(theta * i), m_height, m_radius * sin(theta * i)), QVector3D(cos(theta * i), 0, sin(theta * i)), m_color, QVector2D(tx, 1));
		//Vertex v = Vertex(QVector3D(m_radius * cos(theta * i), yPos, m_radius * sin(theta * i)));
	}
}

void Cylinder::setBasePositionZ(float angle)
{
	const QMatrix4x4 rot = Camera::createRotationZ(InterpolationManager::convertToRadians(angle));
	for (auto &v : m_vertices)
	{
		v.setPosition(rot * v.getPosition());
		v.setNormal(rot * v.getNormal());
	}
}

void Cylinder::setBasePositionX(float angle)
{
	const QMatrix4x4 rot = Camera::createRotationX(InterpolationManager::convertToRadians(angle));
	for (auto &v : m_vertices)
	{
		v.setPosition(rot * v.getPosition());
		v.setNormal(rot * v.getNormal());
	}
}


void Cylinder::generateIndices()
{
	for (int i = 0; i < m_vertices.size() / 2 - 1; ++i)
	{
		m_indices.push_back(2 * i + 1);
		m_indices.push_back(2 * i + 2);
		m_indices.push_back(2 * i);

		m_indices.push_back(2 * i + 1);
		m_indices.push_back(2 * i + 3);
		m_indices.push_back(2 * i + 2);
	}
	const int vCount = m_vertices.size() - 1;
	m_indices.push_back(vCount);
	m_indices.push_back(0);
	m_indices.push_back(vCount - 1);

	m_indices.push_back(vCount);
	m_indices.push_back(1);
	m_indices.push_back(0);

}

QOpenGLBuffer::UsagePattern Cylinder::getDrawPattern() const
{
	return m_drawPattern;
}
