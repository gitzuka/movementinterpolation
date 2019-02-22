#include "Renderer.h"
#include <qmath.h>

Renderer::Renderer() : m_camera(Camera())
{
}

Renderer::~Renderer()
{
}

void Renderer::addGraphicComponent(const std::shared_ptr<Graphics>& graphics)
{
	m_graphics.push_back(graphics);
}

std::shared_ptr<Graphics> Renderer::getGraphics(int index)
{
	return m_graphics.at(index);
}

void Renderer::draw()
{
	for (std::vector<std::shared_ptr<Graphics>>::iterator it = m_graphics.begin(); it != m_graphics.end(); ++it)
	{
		(*it)->draw(m_camera.m_projView);
	}
}

Camera& Renderer::getCamera()
{
	return m_camera;
}

void Renderer::resetCamera()
{
	m_camera = Camera();
}
