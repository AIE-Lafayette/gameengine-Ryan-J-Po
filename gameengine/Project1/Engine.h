#pragma once

namespace GameEngine
{
	class Engine
	{
	public:
		Engine() {}

		static double getDeltaTime() { return m_deltaTime; }

		bool getApplicationShouldClose() { return m_applicationShouldClose; };
		void setApplicationShouldClose(bool value) { m_applicationShouldClose = value; }

		void run();
	private:
		void start();
		void update(double deltaTime);
		void end();
		void draw();

	private:
		bool m_applicationShouldClose = false;
		static double m_deltaTime;
	};

}

