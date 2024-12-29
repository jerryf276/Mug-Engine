#pragma once


namespace mug {

	class Application
	{
	public:

		virtual void update(float dt) = 0;
		virtual void render(RenderSystem * renderSys) = 0;
	private:

	protected:
	//	RenderSystem* renderSystem;
	};

	extern Application* createApp();
}

