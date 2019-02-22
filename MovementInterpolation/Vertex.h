#pragma once
#include <QVector3D>
#include <qvector2d.h>

class Vertex
{
public:
	Vertex();
	explicit Vertex(const QVector3D &position);
	Vertex(const QVector3D &position, const QVector3D &normal, const QVector3D &color, const QVector2D &textureCoord);

	static const int PositionTupleSize = 3;
	static const int ColorTupleSize = 3;
	static const int NormalTupleSize = 3;
	static const int TextureCoordTupleSize = 2;

	const QVector3D &getPosition() const;
	const QVector3D &getNormal() const;
	const QVector3D &getColor() const;
	const QVector2D &getTextureCoord() const;
	void setPosition(const QVector3D &position);
	void setTextureCoord(const QVector2D &textureCoord);
	void setNormal(const QVector3D &normal);
	void setColor(const QVector3D &color);
	static int getPositionOffset();
	static int getNormalOffset();
	static int getTextureCoordOffset();
	static int getColorOffset();
	static int getStride();

private:
	QVector3D m_position;
	QVector3D m_normal;
	QVector3D m_color;
	QVector2D m_texCoord;
};
