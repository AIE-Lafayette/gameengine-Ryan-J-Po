#pragma once
#include "List.h"

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

        void addComponent(Component* component);
        
        template<typename T>
        T* addComponent();

        template<typename T>
        T* getComponent();

        bool getStarted() { return m_started; }

        bool getEnabled() { return m_enabled; };
        void setEnabled(bool value);

    private:
        bool m_enabled;
        bool m_started;
        List<Component*> m_components;
    };

    template<typename T>
    inline T* Entity::addComponent()
    {
        Component* component = new T();

        component->setOwner(this);
        m_components.add(components);

        return (T*)component;
    }

    template<typename T>
    inline T* Entity::getComponent()
    {
        T* result = nullptr;

        for (Component* component : m_components)
        {
            if (result = dynamic_cast<T*>(component))
            {
                break;
            }
        }
        return result;
    }
}

