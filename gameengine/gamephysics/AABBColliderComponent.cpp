#include "AABBColliderComponent.h"
#include <GameMath/Vector3.h>
#include <Raylib/raylib.h>
#include "Project1/TransformComponent.h"
#include "Project1/Engine.h"
#include "Project1/Scene.h"

GamePhysics::Collision* GamePhysics::AABBColliderComponent::checkCollisionCircle(CircleColliderComponent* other)
{
	return nullptr;
}

GamePhysics::Collision* GamePhysics::AABBColliderComponent::checkCollisionAABB(AABBColliderComponent* other)
{
	getRight() > other->getLeft() &&
	getBottom() < other->getTop() &&
	getTop() > other->getBottom() &&
	getLeft() < other->getRight()

	return nullptr;
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
