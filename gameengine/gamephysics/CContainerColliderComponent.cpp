#include "CContainerColliderComponent.h"
#include "CircleColliderComponent.h"
#include "AABBColliderComponent.h"
#include <GameMath/Vector3.h>
#include "Project1/TransformComponent.h"
#include <Raylib/raylib.h>

GamePhysics::Collision* GamePhysics::CContainerColliderComponent::checkCollisionCircle(CircleColliderComponent* other)
{
    GameMath::Vector3 position = getOwner()->getTransform()->getGlobalPosition();
    GameMath::Vector3 otherPosition = other->getOwner()->getTransform()->getGlobalPosition();

    GameMath::Vector3 direction = otherPosition - position;
    float distance = direction.getMagnitude();

    if (distance <= getRadius() - other->getRadius())
    {
        return nullptr;
    }

    GamePhysics::Collision* collisionData = new GamePhysics::Collision();

    collisionData->collider = other;
    collisionData->normal = direction.getNormalized();
    collisionData->contactPoint = getOwner()->getTransform()->getGlobalPosition() + direction.getNormalized() * getRadius();
    //collisionData->penetrationDistance = other->getRadius() + getRadius() - distance;

    return collisionData;
}

GamePhysics::Collision* GamePhysics::CContainerColliderComponent::checkCollisionAABB(AABBColliderComponent* other)
{
	GamePhysics::Collision* collisionData = new GamePhysics::Collision();

	GameMath::Vector3 position = other->getOwner()->getTransform()->getGlobalPosition();
	GameMath::Vector3 circlePosition = getOwner()->getTransform()->getGlobalPosition();

	GameMath::Vector3 direction = circlePosition - position;

	if (direction.x > other->getWidth())
	{
		direction.x = other->getWidth() / 2;
	}
	else if (direction.x < -other->getWidth() / 2)
	{
		direction.x = -other->getWidth() / 2;
	}
	if (direction.y > other->getHeight() / 2)
	{
		direction.y = other->getHeight() / 2;
	}
	else if (direction.y < -other->getHeight() / 2)
	{
		direction.y = -other->getHeight() / 2;
	}

	GameMath::Vector3 closestPoint = position + direction;

	GameMath::Vector3 circleToPoint = closestPoint - other->getOwner()->getTransform()->getGlobalPosition();

	float distance = circleToPoint.getMagnitude();

	if (distance < getRadius())
	{
		return nullptr;
	}

	collisionData->collider = other;
	collisionData->normal = direction.getNormalized();
	collisionData->contactPoint = closestPoint;
	collisionData->penetrationDistance = getRadius() - distance;

	return collisionData;
}

void GamePhysics::CContainerColliderComponent::draw()
{
    GameMath::Vector3 position = getOwner()->getTransform()->getGlobalPosition();

    unsigned int colorCode = getColor();

    RAYLIB_H::DrawCircleLines(position.x, position.y, getRadius(), GetColor(colorCode));
}
