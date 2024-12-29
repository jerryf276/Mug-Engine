#include "Core.h"

namespace mug {

	Core::Core() : mugApp(mug::createApp())
	{
		renderSystem = new RenderSystem();
		renderSystem->setTargetFPS(60);

		//renderSystem->initWindow(1280, 720, "Game");


	}
	void Core::openWindow(int screenWidth, int screenHeight, const char* title)
	{
		renderSystem->initWindow(screenWidth, screenHeight, title);
		rlImGuiSetup(true);
	}
	void Core::close()
	{
		renderSystem->closeWindow();
		rlImGuiShutdown();
	}
	void Core::update(float dt)
	{
		mugApp->update(dt);
	}
	void Core::render()
	{
		mugApp->render();
	}
	int Core::runEngine()
	{
		openWindow(1280, 720, "Mug Engine");
		while (!renderSystem->windowShouldClose())
		{
		//	renderSystem->beginDrawing();
		//	renderSystem->clearBackground(RAYWHITE);
		//	renderSystem->endDrawing();
			update(renderSystem->getFrameTime());
			render();
		}
		close();
		return 0;
	}
}
