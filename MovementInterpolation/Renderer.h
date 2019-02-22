#pragma once
#include "Graphics.h"
#include <memory>
#include "Camera.h"

class Renderer
{
public:
	Renderer();
	~Renderer();

	void addGraphicComponent(const std::shared_ptr<Graphics>& graphics);
	std::shared_ptr<Graphics> getGraphics(int index);
	void draw();
	Camera& getCamera();
	void resetCamera();

private:
	std::vector<std::shared_ptr<Graphics>> m_graphics;
	Camera m_camera;
};
