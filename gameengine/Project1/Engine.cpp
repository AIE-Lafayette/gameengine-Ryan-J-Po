#include "Engine.h"
#include <chrono>
#include "Scene.h"
#include "gamegraphics/Window.h"

GameEngine::Scene* GameEngine::Engine::m_currentScene = nullptr;
double GameEngine::Engine::m_deltaTime = 0;
double GameEngine::Engine::m_fixedTimeStep = 0.01;

GameGraphics::Window* GameEngine::Engine::m_windowWrapper = nullptr;

bool GameEngine::Engine::getApplicationShouldClose()
{
	return m_windowWrapper->getShouldClose();
}

void GameEngine::Engine::closeApplication()
{
	m_windowWrapper->close();
}

void GameEngine::Engine::run()
{
	double lastTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
	double deltaTime = 0;
	double accumulatedTime = 0;
	

	m_windowWrapper = new GameGraphics::Window(800, 600, "Test Application");
	m_windowWrapper->open();

	start();

	while (!getApplicationShouldClose())
	{

		double fixedTimeStep = getTimeStep();
		double currentTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
		deltaTime = currentTime - lastTime;

		lastTime = currentTime;

		m_deltaTime = deltaTime / 1000;

		accumulatedTime += m_deltaTime;

		update(m_deltaTime);

		while (accumulatedTime >= fixedTimeStep)
		{
			fixedUpdate();
			accumulatedTime -= fixedTimeStep;
		}

		m_windowWrapper->beginDrawing();
		draw();
		m_windowWrapper->endDrawing();

	}

	end();

	m_windowWrapper->close();
}

void GameEngine::Engine::start()
{
	m_currentScene->start();
}

void GameEngine::Engine::update(double deltaTime)
{
	m_currentScene->update(deltaTime);
}

void GameEngine::Engine::fixedUpdate()
{
	m_currentScene->fixedUpdate();
}

void GameEngine::Engine::end()
{
	m_currentScene->end();
}

void GameEngine::Engine::draw()
{
	m_currentScene->draw();
}
