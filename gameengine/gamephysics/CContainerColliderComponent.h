#pragma once
#include "ColliderComponent.h"
namespace GamePhysics
{
	class CContainerColliderComponent : public ColliderComponent
	{
	public:
		CContainerColliderComponent(float radius) : ColliderComponent() { m_radius = radius; }

		GamePhysics::Collision* checkCollisionCircle(CircleColliderComponent* other) override;
		GamePhysics::Collision* checkCollisionAABB(AABBColliderComponent* other) override;
		GamePhysics::Collision* checkCollisionContainer(CContainerColliderComponent* other) override { return nullptr; }

		void draw() override;

		float getRadius() { return m_radius; }
		void setRadius(float radius) { m_radius = radius; }

	private:
		float m_radius;
	};
}

