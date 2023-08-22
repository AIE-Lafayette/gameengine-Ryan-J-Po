#pragma once

namespace GameEngine
{
	class Entity;

	class Component
	{
	public:
		Component() { m_enabled = true; }

		virtual void start() {}
		virtual void update(double deltaTime) {}
		virtual void draw() {}
		virtual void end() {}

		virtual void onEnable() {}
		virtual void onDisable() {}

		bool getEnabled() { return m_enabled; }
		void setEnabled(bool enabled);

		Entity* getOwner() { return m_owner; }
		void setOwner(Entity* entity) { m_owner = entity; }

	private:
		bool m_enabled;
		Entity* m_owner;
	};
}

