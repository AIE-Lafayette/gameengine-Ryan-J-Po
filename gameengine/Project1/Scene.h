#pragma once
#include "Entity.h"

namespace GameEngine
{
	class Scene
	{
	public:
		Scene() { m_entities = List<Entity*>(); }

		void start();
		void update(double deltaTime);
		void end();
		void draw();

		virtual void onStart() {}
		virtual void onUpdate(double deltaTime) {}
		virtual void onEnd() {}
		virtual void onDraw() {}

		void addEntity(Entity* entity);

		void removeEntity(Entity* entity);

	private:
		List<Entity*> m_entities;
	};

}
