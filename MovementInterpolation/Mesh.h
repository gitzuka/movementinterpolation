#pragma once
#include "Vertex.h"
#include <qopengl.h>
#include <QMatrix4x4>
#include <qopengltexture.h>
#include <QOpenGLBuffer>

class Mesh
{
public:
	//Mesh(const std::vector<Vertex>& vertices, const std::vector<GLuint>& indices, GLenum drawMode);
	Mesh(GLenum drawMode);
	virtual ~Mesh() = 0;

	friend class Graphics;

	virtual void generateVertices() = 0;
	virtual void generateIndices() = 0;

	GLenum getDrawMode() const;
	const std::vector<Vertex>& getVertices() const;
	const std::vector<GLuint>& getIndices() const;
	const QMatrix4x4& getModelMatrix() const;
	void setModelMatrix(const QMatrix4x4 &mat);
	void setScale(float scale);
	void setPosition(const QVector3D &position);
	void setRotation(const QVector3D &eulerAngles);
	void setRotation(const QQuaternion &q);
	QOpenGLTexture* getTexture();
	//int getIndex() const;
	void updateVerticesPositions(const std::vector<QVector3D> &positions);
	void updateVertexBufferData(int offset, const std::vector<Vertex> &vertices);
	void setDrawState(bool draw);
	bool getDrawState() const;
	int getId() const;

protected:
	std::vector<Vertex> m_vertices;
	std::vector<GLuint> m_indices;
	QMatrix4x4 m_modelMatrix;
	GLenum m_drawMode;
	QOpenGLTexture *m_texture;

private:
	//const int m_index;
	QVector3D m_position;
	QVector3D m_eulerAngles;
	QQuaternion m_rotation;
	float m_scale;
	QOpenGLBuffer m_vbo;
	QOpenGLBuffer m_ibo;
	bool m_draw;
	static int current_id;
	int m_id;
};
