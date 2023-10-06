#include "ShapeComponent.h"

void GameGraphics::ShapeComponent::draw()
{
	GameMath::Vector3 position = getOwner()->getTransform()->getGlobalPosition();

	GameMath::Vector4 color = m_color;

	GameMath::Vector3 scale = getOwner()->getTransform()->getGlobalScale();

	if (m_shapeType == CIRCLE)
	{
		GameGraphics::Gizmos::drawCircle({ position.x, position.y }, scale.x, 50, color);
	}
	//Checks to see if the ShapeType is the CIRCLE_CONTAINER, calls RAYLIB's draw function and uses the owner's x and y position, as well as the owner's x and y scale. 
	//Also draws the assigned color given to the owner.
	else if (m_shapeType == CIRCLE_CONTAINER)
	{
		GameGraphics::Gizmos::drawCircle({ position.x, position.y }, scale.x, 50, color);
	}
	else if (m_shapeType == BOX)
	{
		GameGraphics::Gizmos::drawBoxLines({scale.x, scale.y}, {position.x, position.y}, m_color);
	}
}
