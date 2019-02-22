#include "Vertex.h"
#include <QVector3D>

Vertex::Vertex()
= default;

Vertex::Vertex(const QVector3D &position) : m_position(position)
{
}

Vertex::Vertex(const QVector3D &position, const QVector3D &normal, const QVector3D &color, const QVector2D &textureCoord)
	: m_position(position), m_normal(normal), m_color(color), m_texCoord(textureCoord)
{
}

const QVector3D &Vertex::getPosition() const
{
	return  m_position;
}

const QVector3D &Vertex::getNormal() const
{
	return m_normal;
}

const QVector3D& Vertex::getColor() const
{
	return m_color;
}

const QVector2D& Vertex::getTextureCoord() const
{
	return m_texCoord;
}

void Vertex::setPosition(const QVector3D &position)
{
	m_position = position;
}

void Vertex::setTextureCoord(const QVector2D &textureCoord)
{
	m_texCoord = textureCoord;
}

void Vertex::setNormal(const QVector3D &normal)
{
	m_normal = normal;
}

void Vertex::setColor(const QVector3D& color)
{
	m_color = color;
}

int Vertex::getPositionOffset()
{
	return offsetof(Vertex, m_position);
}

int Vertex::getNormalOffset()
{
	return offsetof(Vertex, m_normal);
}

int Vertex::getTextureCoordOffset()
{
	return offsetof(Vertex, m_texCoord);
}

int Vertex::getColorOffset()
{
	return offsetof(Vertex, m_color);
}

int Vertex::getStride()
{
	return sizeof(Vertex);
}
