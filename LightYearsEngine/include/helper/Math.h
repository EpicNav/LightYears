#pragma once
#include "SFML/System/Vector2.hpp"

namespace ly
{
    sf::Vector2f RotationToVector(float rotation);

    float DegreesToRadians(float degrees);
    float RadiansToDegrees(float radians);
}
