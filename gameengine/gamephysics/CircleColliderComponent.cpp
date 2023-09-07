#include "CircleColliderComponent.h"
#include "AABBColliderComponent.h"
#include <GameMath/Vector3.h>
#include "Project1/TransformComponent.h"
#include <Raylib/raylib.h>

GamePhysics::Collision* GamePhysics::CircleColliderComponent::checkCollisionCircle(CircleColliderComponent* other)
{
    GameMath::Vector3 position = getOwner()->getTransform()->getGlobalPosition();
    GameMath::Vector3 otherPosition = other->getOwner()->getTransform()->getGlobalPosition();

    GameMath::Vector3 direction = otherPosition - position;
    float distance = direction.getMagnitude();

    if (distance > other->getRadius() + getRadius())
    {
        return nullptr;
    }

    GamePhysics::Collision* collisionData = new GamePhysics::Collision();

    collisionData->collider = other;
    collisionData->normal = direction.getNormalized();

    return collisionData;
}

GamePhysics::Collision* GamePhysics::CircleColliderComponent::checkCollisionAABB(AABBColliderComponent* other)
{
    GamePhysics::Collision* collisionData = other->checkCollisionCircle(this);

    GameMath::Vector3 position = getOwner()->getTransform()->getGlobalPosition();
    GameMath::Vector3 otherPosition = other->getOwner()->getTransform()->getGlobalPosition();

    GameMath::Vector3 direction = otherPosition - position;
    float distance = direction.getMagnitude();

    collisionData->collider = other;
    collisionData->normal = direction.getNormalized();


    return collisionData;
}

void GamePhysics::CircleColliderComponent::draw()
{
    GameMath::Vector3 position = getOwner()->getTransform()->getGlobalPosition();

    unsigned int colorCode = getColor();

    RAYLIB_H::DrawCircleLines(position.x, position.y, getRadius(), GetColor(colorCode));
}