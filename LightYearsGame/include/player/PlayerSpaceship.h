#pragma once
#include "spaceship/spaceship.h"

namespace ly
{
    class PlayerSpaceship : public Spaceship
    {
    public:
        PlayerSpaceship(World* owning_world, const std::string& texture_path = "SpaceShooterRedux/PNG/playerShip1_blue.png");

        virtual void Tick(float DeltaTime) override;
        void SetSpeed(float speed);
        float GetSpeed() const { return m_speed_; }

    private:
        void HandleInput();
        void ConsumeInput(float DeltaTime);
        
        sf::Vector2f m_move_input_;
        float m_speed_;
    };
}
