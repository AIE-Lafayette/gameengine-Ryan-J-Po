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

    if (distance < getRadius() - other->getRadius())
    {
        return nullptr;
    }

    GamePhysics::Collision* collisionData = new GamePhysics::Collision();

    collisionData->collider = other;
    collisionData->normal = direction.getNormalized();
    collisionData->contactPoint = getOwner()->getTransform()->getGlobalPosition() + direction.getNormalized() * getRadius();
    collisionData->penetrationDistance = other->getRadius() + getRadius() - distance;

    return collisionData;
}
