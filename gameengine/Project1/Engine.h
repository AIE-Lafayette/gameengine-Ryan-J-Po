#pragma once

namespace GameEngine
{
	class Scene;

	class Engine
	{
	public:
		Engine() {}

		static double getDeltaTime() { return m_deltaTime; }

		static void setCurrentScene(Scene* scene) { m_currentScene = scene; }
		static Scene* getCurrentScene() { return m_currentScene; }

		static bool getApplicationShouldClose() { return m_applicationShouldClose; };
		static void setApplicationShouldClose(bool value) { m_applicationShouldClose = value; }

		void run();
	private:
		void start();
		void update(double deltaTime);
		void end();
		void draw();

	private:
		static bool m_applicationShouldClose;
		static double m_deltaTime;
		static Scene* m_currentScene;
	};

}

