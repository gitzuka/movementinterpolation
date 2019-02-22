#include "Mesh.h"
#include "Camera.h"

int Mesh::current_id = 0;

Mesh::Mesh(GLenum drawMode) : m_drawMode(drawMode), m_draw(true), m_id(current_id++)
{
}

//Mesh::Mesh(const std::vector<Vertex>& vertices, const std::vector<GLuint>& indices, GLenum drawMode)
//	: m_vertices(vertices), m_indices(indices), m_drawMode(drawMode), m_draw(true), m_id(current_id++)
//{
//}

Mesh::~Mesh()
= default;

GLenum Mesh::getDrawMode() const
{
	return m_drawMode;
}

const std::vector<Vertex>& Mesh::getVertices() const
{
	return m_vertices;
}

const std::vector<GLuint>& Mesh::getIndices() const
{
	return m_indices;
}

const QMatrix4x4& Mesh::getModelMatrix() const
{
	return m_modelMatrix;
}

void Mesh::setModelMatrix(const QMatrix4x4& mat)
{
	m_modelMatrix = mat;
}

void Mesh::setScale(float scale)
{
	m_scale = scale;
	//m_modelMatrix = Camera::createTranslation(m_position) * Camera::createScaling(m_scale);
	m_modelMatrix = Camera::createTranslation(m_position) * QMatrix4x4(m_rotation.toRotationMatrix()) * Camera::createScaling(m_scale);
}

void Mesh::setPosition(const QVector3D& position)
{
	m_position = position;
	//m_modelMatrix = Camera::createTranslation(m_position) * Camera::createScaling(m_scale);
	//m_modelMatrix = Camera::createScaling(m_scale) * Camera::createTranslation(m_position);
	m_modelMatrix = Camera::createTranslation(m_position) * QMatrix4x4(m_rotation.toRotationMatrix()) * Camera::createScaling(m_scale);
}

void Mesh::setRotation(const QVector3D& eulerAngles)
{
	m_eulerAngles = eulerAngles;
	const QMatrix4x4 rot = Camera::createRotationZ(m_eulerAngles.z()) * Camera::createRotationY(m_eulerAngles.y()) * Camera::createRotationX(m_eulerAngles.x());
	m_modelMatrix = Camera::createTranslation(m_position) * rot * Camera::createScaling(m_scale);
}

void Mesh::setRotation(const QQuaternion& q)
{
	m_rotation = q;
	m_modelMatrix = Camera::createTranslation(m_position) * QMatrix4x4(m_rotation.toRotationMatrix()) * Camera::createScaling(m_scale);
}

QOpenGLTexture* Mesh::getTexture()
{
	return m_texture;
}

//int Mesh::getIndex() const
//{
//	return m_index;
//}

void Mesh::updateVerticesPositions(const std::vector<QVector3D>& positions)
{
	auto vit = m_vertices.begin();
	auto it = positions.begin();
	for (it = positions.begin(); (it != positions.end() || vit != m_vertices.end()); ++it, ++vit)
	{
		vit->setPosition(*it);
	}
}

void Mesh::updateVertexBufferData(int offset, const std::vector<Vertex>& vertices)
{
	m_vbo.bind();
	m_vbo.write(offset * sizeof(Vertex), vertices.data(), sizeof(Vertex) * vertices.size());
	m_vbo.release();
}

void Mesh::setDrawState(bool draw)
{
	m_draw = draw;
}

bool Mesh::getDrawState() const
{
	return m_draw;
}

int Mesh::getId() const
{
	return m_id;
}
