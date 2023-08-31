#include "Scene.h"
#include "Entity.h"
#include "gamephysics/ColliderComponent.h"

void GameEngine::Scene::start()
{

	for (Entity* entity : m_entities)
	{
		if (entity->getEnabled())
			entity->start();
	}

	onStart();
}

void GameEngine::Scene::update(double deltaTime)
{
	for (Entity* entity : m_entities)
	{
		if (!entity->getEnabled())
		{
			continue;
		}

		if (!entity->getStarted())
		{
			entity->start();
		}

			entity->update(deltaTime);
	}

	onUpdate(deltaTime);

	for (GamePhysics::ColliderComponent* collider1 : m_activeColliders)
	{
		for (GamePhysics::ColliderComponent* collider2 : m_activeColliders)
		{
			if (collider1 == collider2 || !collider2->getOwner()->getEnabled() || !collider1->getOwner()->getEnabled())
			{
				continue;
			}

			GamePhysics::Collision* collisionData1 = nullptr;
			GamePhysics::Collision* collisionData2 = new GamePhysics::Collision();

			if (collisionData1 = collider1->checkCollision(collider2))
			{
				collider1->getOwner()->onCollision(collisionData1);

				collisionData2->collider = collider1;
				collisionData2->normal = collisionData1->normal * -1;

				collider2->getOwner()->onCollision(collisionData2);
			}
		}
	}
}

void GameEngine::Scene::end()
{
	for (Entity* entity : m_entities)
	{
		if (entity->getEnabled())
			entity->end();
	}

	onEnd();
}

void GameEngine::Scene::draw()
{
	for (Entity* entity : m_entities)
	{
		if (entity->getEnabled())
			entity->draw();
	}

	onDraw();
}

void GameEngine::Scene::addEntity(Entity* entity)
{
	m_entities.add(entity);
}

void GameEngine::Scene::removeEntity(Entity* entity)
{
	m_entities.remove(entity);
}
