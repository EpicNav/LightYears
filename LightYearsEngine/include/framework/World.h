#pragma once
#include "framework/Core.h"
#include "SFML/Graphics/RenderWindow.hpp"

namespace ly
{
    class Actor;
    class Application;
    
    class World
    {
    public:
        World(Application* InOwningApp);
        virtual ~World();
        
        void BeginPlayInternal();
        void TickInternal(float deltaTime);
        void Render(sf::RenderWindow &InWindow);

        template<typename T>
		TWeakPtr<T> SpawnActor();

    protected:
        virtual void BeginPlay();
        virtual void Tick(float deltaTime);

    private:
        Application* m_OwningApp;
        bool bBeginPlay;

        TArray<TSharedPtr<Actor>> m_actors_;
        TArray<TSharedPtr<Actor>> m_pending_actors_;
    };

    template<typename ActorType>
    TWeakPtr<ActorType> World::SpawnActor()
    {
        TSharedPtr<ActorType> newActor{ new ActorType(this) };
        m_pending_actors_.push_back(newActor);
        return newActor;
    }
}
