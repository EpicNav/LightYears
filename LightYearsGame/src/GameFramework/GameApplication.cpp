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
    }
}
