#include "GameFramework/GameApplication.h"
#include "framework/World.h"
#include "framework/Actor.h"

ly::Application* GetApplication()
{
    return new ly::GameApplication();
}

namespace ly
{
    GameApplication::GameApplication()
    {
        TWeakPtr<World> newWorld = LoadWorld<World>();
        newWorld.lock()->SpawnActor<Actor>();
        ActorToDestroyRef = newWorld.lock()->SpawnActor<Actor>();

        counter = 0;
    }

    void GameApplication::Tick(float DeltaTime)
    {
        Application::Tick(DeltaTime);

        counter += DeltaTime;
        
        LOG("TICKING %f", counter);

        if (counter > 2.f)
        {
            if (!ActorToDestroyRef.expired())
            {
                ActorToDestroyRef.lock()->DestroyInternal();
            }
        }
    }
}
