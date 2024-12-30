#pragma once


namespace mug {

	class Application
	{
	public:

		virtual void update(float dt) = 0;
		virtual void render() = 0;
	private:

	protected:
		RenderSystem* renderer = new RenderSystem();
		Input* input = new Input();
	//	DoubleEndedStackAllocator* stack = new DoubleEndedStackAllocator(size_t(1000000));
	};

	extern Application* createApp(RenderSystem* renderSys, Input* input);
}

