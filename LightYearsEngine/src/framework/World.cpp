#include "framework/World.h"
#include "framework/Core.h"

namespace ly
{
    World::World(Application* InOwningApp)
        : m_OwningApp(InOwningApp)
        , bBeginPlay(false)
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
