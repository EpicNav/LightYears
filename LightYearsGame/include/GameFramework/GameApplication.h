#pragma once

#include <framework/Application.h>

namespace ly
{
    class PlayerSpaceship;
    class GameApplication : public Application
    {
    public:
        GameApplication();
        virtual void Tick(float DeltaTime) override;

    private:
        float counter;
        TWeakPtr<PlayerSpaceship> testPlayerSpaceship;
    };
}
