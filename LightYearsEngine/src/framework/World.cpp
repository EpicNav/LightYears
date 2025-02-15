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

        for (auto itr = m_actors_.begin(); itr != m_actors_.end();)
        {
            if (itr->get()->IsPendingKill())
            {
                itr = m_actors_.erase(itr);
            } else
            {
                itr->get()->TickInternal(deltaTime);
                ++itr;
            }
        }

        Tick(deltaTime);
    }

    void World::BeginPlay()
    {
        LOG("Begin Play");
    }

    void World::Tick(float deltaTime)
    {
    }
}
