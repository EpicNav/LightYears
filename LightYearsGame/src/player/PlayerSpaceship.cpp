#include "player/PlayerSpaceship.h"
#include "SFML/System.hpp"

namespace ly {
    PlayerSpaceship::PlayerSpaceship(World* owning_world, const std::string& texture_path)
        : Spaceship(owning_world, texture_path)
        , m_move_input_()
        , m_speed_(200.f)
    {
    }

    void PlayerSpaceship::Tick(float DeltaTime)
    {
        Spaceship::Tick(DeltaTime);

        HandleInput();
        ConsumeInput(DeltaTime);
    }

    void PlayerSpaceship::SetSpeed(float speed)
    {
        m_speed_ = speed;
    }

    void PlayerSpaceship::HandleInput()
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        {
            m_move_input_.y = -1.f;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        {
            m_move_input_.y = 1.f;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        {
            m_move_input_.x = -1.f;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        {
            m_move_input_.x = 1.f;
        }
    }

    void PlayerSpaceship::ConsumeInput(float DeltaTime)
    {
        SetVelocity(m_move_input_ * GetSpeed());
        m_move_input_.x = m_move_input_.y = 0.f;
    }
}
