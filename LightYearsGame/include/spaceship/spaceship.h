#pragma once
#include "framework/Actor.h"

namespace ly
{
    class Spaceship : public Actor
    {
    public:
        Spaceship(World* owningWorld, const std::string& texturePath);

        virtual void Tick(float DeltaTime) override;
        void SetVelocity(const sf::Vector2f& InVelocity);
        sf::Vector2f GetVelocity() const { return m_velocity_; }

    private:
        sf::Vector2f m_velocity_;
    };
}
