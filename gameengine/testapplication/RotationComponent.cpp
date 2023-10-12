#include "RotationComponent.h"
#include "Project1/TransformComponent.h"

void RotationComponent::update(double deltaTime)
{
	getOwner()->getTransform()->setLocalRotation({ 0,0, _radians += deltaTime });
}