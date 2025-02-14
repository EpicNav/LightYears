#pragma once
#include "framework/Core.h"

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

    template<typename T>
    TWeakPtr<T> World::SpawnActor()
    {
        TSharedPtr<T> newActor(new T(this));
        m_pending_actors_.push_back(newActor);
        return newActor;
    }
}