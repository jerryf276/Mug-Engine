#pragma once
#include "RenderSystem.h"
#include "Input.h"
#include "imgui.h"
#include "rlImGui.h"
#include "UniquePointer.h"
#include "Application.h"
#include "Audio.h"
#include "DoubleEndedStackAllocator.h"
namespace mug {
	class Core
	{
	public:
		Core();
		int runEngine();
		
	private:
		void openWindow(int screenWidth, int screenHeight, const char* title);
		void close();
		void update(float dt);
		void render();

		
		//void BeginDrawing();
		//void EndDrawing();

		RenderSystem * renderSystem;
		Input* input;
		//DoubleEndedStackAllocator* stackAllocator;
		UniquePointer<mug::Application> mugApp;
		

		//try the c++ built in unique pointer if it doesn't work

	protected:

	};
}
