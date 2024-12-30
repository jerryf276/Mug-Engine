#include "Core.h"
#include <iostream>

namespace mug {

	Core::Core() : mugApp(mug::createApp(renderSystem, input))
	{
		renderSystem = new RenderSystem();
		renderSystem->setTargetFPS(60);
		input = new Input();
		//stackAllocator = new DoubleEndedStackAllocator(size_t(1000000));
		
		//renderSystem->initWindow(1280, 720, "Game");


	}
	void Core::openWindow(int screenWidth, int screenHeight, const char* title)
	{
		renderSystem->initWindow(screenWidth, screenHeight, title);
	//	InitAudioDevice();
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
		renderSystem->beginDrawing();
		mugApp->render();
		renderSystem->endDrawing();
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
		//	int x = renderSystem->getFPS();
			//std::cout << renderSystem->getFPS();
			render();
		}
		close();
		return 0;
	}
}
