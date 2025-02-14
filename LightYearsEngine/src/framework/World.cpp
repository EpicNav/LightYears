#include "framework/World.h"

#include "framework/Actor.h"
#include "framework/Core.h"

namespace ly
{
    World::World(Application* InOwningApp)
        : m_OwningApp(InOwningApp)
        , bBeginPlay(false)
        , m_actors_()
        , m_pending_actors_()
    {
    }

    World::~World()
    {
    }

    void World::BeginPlayInternal()
    {
        if (!bBeginPlay)
        {
            BeginPlay();
            bBeginPlay = true;
        }
    }

    void World::TickInternal(float deltaTime)
    {
        for (TSharedPtr<Actor> actor : m_pending_actors_)
        {
            m_actors_.push_back(actor);
            actor->BeginPlayInternal();
        }
        
        m_pending_actors_.clear();

        for (TSharedPtr<Actor> actor : m_actors_)
        {
            actor->TickInternal(deltaTime);
        }

        Tick(deltaTime);
    }

    void World::BeginPlay()
    {
        LOG("Begin Play");
    }

    void World::Tick(float deltaTime)
    {
        LOG("FPS: %f", 1.f / deltaTime);
    }
}
