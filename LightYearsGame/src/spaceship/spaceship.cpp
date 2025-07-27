#include "spaceship/spaceship.h"

namespace ly
{
    Spaceship::Spaceship(World* owningWorld, const std::string& texturePath)
        : Actor(owningWorld, texturePath)
    {
    }

    void Spaceship::Tick(float DeltaTime)
    {
        Actor::Tick(DeltaTime);

        SetActorLocationOffset(GetVelocity() * DeltaTime);
    }

    void Spaceship::SetVelocity(const sf::Vector2f& InVelocity)
    {
        m_velocity_ = InVelocity;
    }
}
