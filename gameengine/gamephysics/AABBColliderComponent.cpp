#include "AABBColliderComponent.h"
#include "CircleColliderComponent.h"
#include <GameMath/Vector3.h>
#include <Raylib/raylib.h>
#include "Project1/TransformComponent.h"
#include "Project1/Engine.h"
#include "Project1/Scene.h"

GamePhysics::AABBColliderComponent::AABBColliderComponent(float width, float height)
{
	m_width = width;
	m_height = height;
}

GamePhysics::Collision* GamePhysics::AABBColliderComponent::checkCollisionCircle(CircleColliderComponent* other)
{
	GamePhysics::Collision* collisionData = new GamePhysics::Collision();

	GameMath::Vector3 position = getOwner()->getTransform()->getGlobalPosition();
	GameMath::Vector3 circlePosition = other->getOwner()->getTransform()->getGlobalPosition();

	GameMath::Vector3 direction = circlePosition - position;

	if (direction.x > m_width / 2)
	{
		direction.x = m_width / 2;
	}
	if (direction.x < -m_width / 2)
	{
		direction.x = -m_width / 2;
	}
	if (direction.y > m_height / 2)
	{
		direction.y = m_height / 2;
	}
	if (direction.y < -m_height / 2)
	{
		direction.y = -m_height / 2;
	}

	GameMath::Vector3 closestPoint = position + direction;

	GameMath::Vector3 circleToPoint = closestPoint - other->getOwner()->getTransform()->getGlobalPosition();

	float distance = circleToPoint.getMagnitude();

	if (distance > other->getRadius())
	{
		return nullptr;
	}

	collisionData->collider = other;
	collisionData->normal = direction.getNormalized();

	return collisionData;

}

GamePhysics::Collision* GamePhysics::AABBColliderComponent::checkCollisionAABB(AABBColliderComponent* other)
{
	GamePhysics::Collision* collisionData = new GamePhysics::Collision();

	bool isCollision = getRight() > other->getLeft() &&
		getBottom() < other->getTop() &&
		getTop() > other->getBottom() &&
		getLeft() < other->getRight();

	if (!isCollision)
	{
		return nullptr;
	}

	GameMath::Vector3 position = getOwner()->getTransform()->getGlobalPosition();
	GameMath::Vector3 otherPosition = other->getOwner()->getTransform()->getGlobalPosition();

	GameMath::Vector3 direction = otherPosition - position;
	float distance = direction.getMagnitude();

	collisionData->collider = other;
	collisionData->normal = direction.getNormalized();

	return collisionData;
	
}

void GamePhysics::AABBColliderComponent::draw()
{
	GameMath::Vector3 position = getOwner()->getTransform()->getGlobalPosition();

	unsigned int colorCode = getColor();

	RAYLIB_H::DrawRectangleLines(getLeft(), getBottom(), m_width, m_height, GetColor(colorCode));
}

float GamePhysics::AABBColliderComponent::getLeft()
{
	return getOwner()->getTransform()->getGlobalPosition().x - m_width / 2;
}

float GamePhysics::AABBColliderComponent::getRight()
{
	return getOwner()->getTransform()->getGlobalPosition().x + m_width / 2;
	
}

float GamePhysics::AABBColliderComponent::getTop()
{
	return getOwner()->getTransform()->getGlobalPosition().y + m_height / 2;
}

float GamePhysics::AABBColliderComponent::getBottom()
{
	return getOwner()->getTransform()->getGlobalPosition().y - m_height / 2;
}
