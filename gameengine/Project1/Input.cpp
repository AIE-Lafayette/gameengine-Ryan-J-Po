#include "Input.h"
#include "Engine.h"
#include <GLFW/glfw3.h>
#include"gamegraphics/Window.h"


bool Input::getLeftMouseButton()
{
	int state = glfwGetMouseButton(GameEngine::Engine::getWindow()->getWindowContext(), GLFW_MOUSE_BUTTON_LEFT);

	return state == GLFW_PRESS;
}

bool Input::getRightMouseButton()
{
	int state = glfwGetMouseButton(GameEngine::Engine::getWindow()->getWindowContext(), GLFW_MOUSE_BUTTON_RIGHT);

	return state == GLFW_PRESS;
}

GameMath::Vector2 Input::getMousePos()
{
	double xPos;
	double yPos;

	glfwGetCursorPos(GameEngine::Engine::getWindow()->getWindowContext(), &xPos, &yPos);
	GameMath::Vector2 position = { (float)xPos, (float)yPos };

	return position;
}
