#pragma once
#include <QOpenGLVertexArrayObject>
#include <QOpenGLShaderProgram>
#include "vertex.h"
#include "mesh.h"
#include <memory>

class Graphics : public QObject
{
	Q_OBJECT
public:
	explicit Graphics(QOpenGLShaderProgram *program);
	virtual ~Graphics();

	void initBuffers();
	void initBuffer(QOpenGLBuffer* vertBuffer, QOpenGLBuffer* indexBuffer, QOpenGLBuffer::UsagePattern bufferUsage,
	                const std::shared_ptr<Mesh>& mesh);
	void initBuffer(int meshId, QOpenGLBuffer::UsagePattern bufferUsage);
	void updateBufferData(int bufferIndex);
	void updateVertexBufferData(int offset, const Vertex *vertex, int bufferIndex, int count);
	void updateVertexBufferData(int offset, const Vertex *vertex, int count, QOpenGLBuffer *buffer);
	void updateVertexBufferData(int offset, const std::vector<Vertex> &vertices, int bufferIndex);
	void addMesh(const std::shared_ptr<Mesh>& mesh, QOpenGLBuffer::UsagePattern bufferUsage);
	void assignMesh(const std::shared_ptr<Mesh>& mesh, QOpenGLBuffer::UsagePattern bufferUsage, int index);
	void assignShaderProgram(QOpenGLShaderProgram *program);
	const std::vector<std::shared_ptr<Mesh>>& getMeshes() const;
	void draw(const QMatrix4x4 &projView);
	void setDrawState(bool draw, int meshId);
	void updateVertices(int meshId, const std::vector<QVector3D> &vertices);
	void deleteMesh(int meshId);
	void deleteMesh(const std::shared_ptr<Mesh>& mesh);
	QOpenGLShaderProgram* getProgram();
	void clearMeshes();

private:
	std::vector<std::shared_ptr<Mesh>> m_meshes;
	std::vector<bool> m_drawState;
	QOpenGLVertexArrayObject m_vao;
	QOpenGLShaderProgram *m_program;

private slots:
	void initializeBuffer(int meshId, QOpenGLBuffer::UsagePattern bufferUsage);

};
