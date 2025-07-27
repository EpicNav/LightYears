#include "GameFramework/GameApplication.h"
#include "framework/World.h"
#include "player/PlayerSpaceship.h"
#include "config.h"
#include "framework/AssetManager.h"

ly::Application* GetApplication()
{
    return new ly::GameApplication();
}

namespace ly
{
    GameApplication::GameApplication()
        : Application(sf::Vector2u(768, 1080), "Light Years")
    {
        AssetManager::Get().SetAssetRootDirectory(GetResourceDir());
        
        TWeakPtr<World> newWorld = LoadWorld<World>();
        testPlayerSpaceship = newWorld.lock()->SpawnActor<PlayerSpaceship>();
        testPlayerSpaceship.lock()->SetActorLocation(sf::Vector2f(384.5f, 540.f));

        counter = 0;
    }

    void GameApplication::Tick(float DeltaTime)
    {
    }
}
