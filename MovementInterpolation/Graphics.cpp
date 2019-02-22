#include "Graphics.h"

Graphics::Graphics(QOpenGLShaderProgram* program) : m_program(program)
{
}

Graphics::~Graphics()
{
	m_vao.destroy();
	for (auto& m_meshe : m_meshes)
	{
		m_meshe->m_vbo.destroy();
		m_meshe->m_ibo.destroy();
	}
	delete m_program;
}

void Graphics::initBuffers()
{
	m_program->bind();

	for (int i = 0; i < m_meshes.size(); ++i)
	{
		if (!m_vao.isCreated())
		{
			m_vao.create();
		}
		m_vao.bind();
		m_meshes[i]->m_vbo = QOpenGLBuffer();
		m_meshes[i]->m_vbo.create();
		m_meshes[i]->m_vbo.bind();
		m_meshes[i]->m_vbo.setUsagePattern(QOpenGLBuffer::StaticDraw);
		m_meshes[i]->m_vbo.allocate(m_meshes.at(i)->getVertices().data(), m_meshes.at(i)->getVertices().size() * sizeof(Vertex));

		m_meshes[i]->m_ibo = QOpenGLBuffer(QOpenGLBuffer::IndexBuffer);
		m_meshes[i]->m_ibo.create();
		m_meshes[i]->m_ibo.bind();
		m_meshes[i]->m_ibo.setUsagePattern(QOpenGLBuffer::StaticDraw);
		m_meshes[i]->m_ibo.allocate(m_meshes.at(i)->getIndices().data(), m_meshes.at(i)->getIndices().size() * sizeof(GLuint));

		m_program->enableAttributeArray(0);
		m_program->enableAttributeArray(1);
		m_program->enableAttributeArray(2);

		m_vao.release();
		m_meshes[i]->m_ibo.release();
		m_meshes[i]->m_vbo.release();
	}
	m_program->release();
}

void Graphics::initBuffer(QOpenGLBuffer* vertBuffer, QOpenGLBuffer* indexBuffer, QOpenGLBuffer::UsagePattern bufferUsage,
	const std::shared_ptr<Mesh>& mesh)
{
	m_program->bind();

	if (!m_vao.isCreated())
	{
		m_vao.create();
	}
	m_vao.bind();
	if (vertBuffer->isCreated())
	{
		vertBuffer->destroy();
	}
	vertBuffer->create();
	vertBuffer->bind();
	vertBuffer->setUsagePattern(bufferUsage);
	vertBuffer->allocate(mesh->getVertices().data(), mesh->getVertices().size() * sizeof(Vertex));

	if (indexBuffer->isCreated())
	{
		indexBuffer->destroy();
	}
	indexBuffer->create();
	indexBuffer->bind();
	indexBuffer->setUsagePattern(QOpenGLBuffer::StaticDraw);
	indexBuffer->allocate(mesh->getIndices().data(), mesh->getIndices().size() * sizeof(GLuint));

	m_program->enableAttributeArray(0);
	m_program->enableAttributeArray(1);
	m_program->enableAttributeArray(2);

	m_vao.release();
	vertBuffer->release();
	indexBuffer->release();
	m_program->release();
}

void Graphics::initBuffer(int meshId, QOpenGLBuffer::UsagePattern bufferUsage)
{
	int bufferIndex = -1;
	for (int i = 0; i < m_meshes.size(); ++i)
	{
		if (meshId == m_meshes[i]->getId())
			bufferIndex = i;
	}
	if (bufferIndex == -1)
		return;
	m_program->bind();

	if (!m_vao.isCreated())
	{
		m_vao.create();
	}
	m_vao.bind();

	m_meshes[bufferIndex]->m_vbo = QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
	m_meshes[bufferIndex]->m_vbo.create();
	m_meshes[bufferIndex]->m_vbo.bind();
	m_meshes[bufferIndex]->m_vbo.setUsagePattern(bufferUsage);
	m_meshes[bufferIndex]->m_vbo.allocate(m_meshes.at(bufferIndex)->getVertices().data(), m_meshes.at(bufferIndex)->getVertices().size() * sizeof(Vertex));

	m_meshes[bufferIndex]->m_ibo = QOpenGLBuffer(QOpenGLBuffer::IndexBuffer);
	m_meshes[bufferIndex]->m_ibo.create();
	m_meshes[bufferIndex]->m_ibo.bind();
	m_meshes[bufferIndex]->m_ibo.setUsagePattern(QOpenGLBuffer::StaticDraw);
	m_meshes[bufferIndex]->m_ibo.allocate(m_meshes.at(bufferIndex)->getIndices().data(), m_meshes.at(bufferIndex)->getIndices().size() * sizeof(GLuint));

	m_program->enableAttributeArray(0);
	m_program->enableAttributeArray(1);
	m_program->enableAttributeArray(2);

	m_vao.release();
	m_meshes[bufferIndex]->m_ibo.release();
	m_meshes[bufferIndex]->m_vbo.release();
	m_program->release();
}

void Graphics::updateBufferData(int bufferIndex)
{
	bool b = m_meshes[bufferIndex]->m_vbo.bind();
	int size = m_meshes[bufferIndex]->m_vbo.size();
	m_meshes[bufferIndex]->m_vbo.allocate(m_meshes.at(bufferIndex)->getVertices().data(), m_meshes.at(bufferIndex)->getVertices().size() * sizeof(Vertex));
	size = m_meshes[bufferIndex]->m_vbo.size();
	m_meshes[bufferIndex]->m_vbo.release();
	m_meshes[bufferIndex]->m_ibo.bind();
	m_meshes[bufferIndex]->m_ibo.allocate(m_meshes.at(bufferIndex)->getIndices().data(), m_meshes.at(bufferIndex)->getIndices().size() * sizeof(GLuint));
	m_meshes[bufferIndex]->m_ibo.release();
}

void Graphics::updateVertexBufferData(int offset, const Vertex *vertex, int bufferIndex, int count)
{
	m_meshes[bufferIndex]->m_vbo.bind();
	m_meshes[bufferIndex]->m_vbo.write(offset * sizeof(Vertex), vertex, sizeof(Vertex) * count);
	m_meshes[bufferIndex]->m_vbo.release();
}

void Graphics::updateVertexBufferData(int offset, const Vertex *vertex, int count, QOpenGLBuffer *buffer)
{
	buffer->bind();
	buffer->write(offset * sizeof(Vertex), vertex, sizeof(Vertex) *count);
	buffer->release();
}

void Graphics::updateVertexBufferData(int offset, const std::vector<Vertex> &vertices, int bufferIndex)
{
	m_meshes[bufferIndex]->m_vbo.bind();
	for (int i = 0; i < vertices.size(); ++i)
	{
		m_meshes[bufferIndex]->m_vbo.write((offset + i) * sizeof(Vertex), vertices.data(), sizeof(Vertex) * vertices.size());
	}
	m_meshes[bufferIndex]->m_vbo.release();
}

void Graphics::addMesh(const std::shared_ptr<Mesh> &mesh, QOpenGLBuffer::UsagePattern bufferUsage)
{
	m_meshes.push_back(mesh);
	m_drawState.push_back(true);
	initBuffer(m_meshes.size() - 1, bufferUsage);
}

void Graphics::assignMesh(const std::shared_ptr<Mesh>& mesh, QOpenGLBuffer::UsagePattern bufferUsage, int index)
{
	m_meshes[index] = mesh;
	initBuffer(index, bufferUsage);
}

void Graphics::assignShaderProgram(QOpenGLShaderProgram* program)
{
	m_program = program;
}

const std::vector<std::shared_ptr<Mesh>>& Graphics::getMeshes() const
{
	return m_meshes;
}

void Graphics::draw(const QMatrix4x4 &projView)
{
	m_program->bind();
	int i = 0;
	for (auto it = m_meshes.begin(); it != m_meshes.end(); ++it)
	{
		//if (!m_drawState.at(i))
		if (!(*it)->getDrawState())
		{
			++i;
			continue;
		}
		m_program->setUniformValue(m_program->uniformLocation("model"), (*it)->getModelMatrix());
		m_program->setUniformValue(m_program->uniformLocation("MVP"), projView * (*it)->getModelMatrix());
		m_program->setUniformValue(m_program->uniformLocation("normalMat"), projView * (*it)->getModelMatrix());
		m_vao.bind();
		m_meshes[i]->m_vbo.bind();
		m_meshes[i]->m_ibo.bind();

		m_program->setAttributeBuffer(0, GL_FLOAT, Vertex::getPositionOffset(), Vertex::PositionTupleSize, Vertex::getStride());
		m_program->setAttributeBuffer(1, GL_FLOAT, Vertex::getNormalOffset(), Vertex::NormalTupleSize, Vertex::getStride());
		m_program->setAttributeBuffer(2, GL_FLOAT, Vertex::getColorOffset(), Vertex::ColorTupleSize, Vertex::getStride());
		glDrawElements((*it)->getDrawMode(), (*it)->getIndices().size(), GL_UNSIGNED_INT, nullptr);
		m_meshes[i]->m_ibo.release();
		m_meshes[i]->m_vbo.release();
		m_vao.release();
		++i;
	}
	m_program->release();
}

void Graphics::setDrawState(bool draw, int meshId)
{
	for (int i = 0; i < m_meshes.size(); ++i)
	{
		if (m_meshes[i]->getId() == meshId)
			m_meshes[i]->setDrawState(draw);
	}
	//m_drawState.at(index) = draw;
}

void Graphics::updateVertices(int meshId, const std::vector<QVector3D>& vertices)
{
	m_meshes[meshId]->updateVerticesPositions(vertices);
	updateVertexBufferData(0, m_meshes[meshId]->getVertices(), meshId);
}

void Graphics::deleteMesh(int meshId)
{
	for (auto it = m_meshes.begin(); it != m_meshes.end(); ++it)
	{
		if (it->get()->getId() == meshId)
		{
			m_meshes.erase(it);
			return;
		}
	}
}

void Graphics::deleteMesh(const std::shared_ptr<Mesh>& mesh)
{
	deleteMesh(mesh->getId());
}

QOpenGLShaderProgram* Graphics::getProgram()
{
	return m_program;
}

void Graphics::clearMeshes()
{
	m_meshes.clear();
}

void Graphics::initializeBuffer(int meshId, QOpenGLBuffer::UsagePattern bufferUsage)
{
	initBuffer(meshId, bufferUsage);
}


