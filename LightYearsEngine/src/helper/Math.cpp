#include "helper\Math.h"
#include <iostream>

namespace ly
{
    const float PI = 3.14159265358979323846f;

    sf::Vector2f RotationToVector(float rotation)
    {
        float radians = DegreesToRadians(rotation);
        return sf::Vector2f(std::cos(radians), std::sin(radians));
    }

    float DegreesToRadians(float degrees)
    {
        return degrees * (PI / 180);
    }

    float RadiansToDegrees(float radians)
    {
        return radians * (180 / PI);
    }
}
