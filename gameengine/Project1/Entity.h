#pragma once

namespace GameEngine
{
	class Component;

    class Entity
    {
    public:
        Entity();

        void start();
        void update(double deltaTime);
        void end();
        void draw();

        virtual void onStart() {}
        virtual void onUpdate(double deltaTime) {}
        virtual void onEnd() {}
        virtual void onDraw() {}
        virtual void onEnable() {}
        virtual void onDisable() {}

        bool getStarted() { return m_started; }

        bool getEnabled() { return m_enabled; };
        void setEnabled(bool value) { m_enabled = value; }

    private:
        bool m_enabled;
        bool m_started;
    };
}

