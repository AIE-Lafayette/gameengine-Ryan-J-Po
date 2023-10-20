#pragma once
#include <GameMath/Vector2.h>

class Input
{
public:
	Input() {};
	//Gets the specific window being used and returns if the left mouse button has been pressed.
	static bool getLeftMouseButton();
	//Gets the specific window being used and returns if the right mouse button has been pressed.
	static bool getRightMouseButton();
	//Gets the specific window being used. Checks where the cursor is, in relation to the window, and returns the position of the cursor in the window.
	static GameMath::Vector2 getMousePos();
private:


};

