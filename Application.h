#pragma once


namespace mug {

	class Application
	{
	public:

		virtual void update(float dt) = 0;
		virtual void render() = 0;
	private:

	protected:

	};

	extern Application* createApp();
}

