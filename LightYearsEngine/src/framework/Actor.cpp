#include "framework/Actor.h"
#include "framework/Core.h"
#include "framework/AssetManager.h"
#include "helper/Math.h"

namespace ly
{
    Actor::Actor(World* owning_world, const std::string& texturePath)
        : m_owning_world_(owning_world)
        , m_begin_play_(false)
        , m_texture_()
        , m_sprite_(m_texture_)
        , m_texture_path_(texturePath)
    {
        SetTextureFromPath(texturePath);
    }

    Actor::~Actor()
    {
        LOG("Actor Destroyed!");
    }

    void Actor::BeginPlayInternal()
    {
        if (!m_begin_play_)
        {
            BeginPlay();
            m_begin_play_ = true;
        }
    }

    void Actor::TickInternal(float DeltaTime)
    {
        if (!IsPendingKill())
        {
            Tick(DeltaTime);
        }
    }

    void Actor::Render(sf::RenderWindow &InWindow)
    {
        if (IsPendingKill()) return;
        
        InWindow.draw(m_sprite_);
    }

    void Actor::BeginPlay()
    {
        LOG("Actor Begin Play");
    }

    void Actor::Tick(float DeltaTime)
    {
    }

    void Actor::SetTextureFromPath(const std::string& texturePath)
    {
        m_texture_ = *AssetManager::Get().LoadTexture(texturePath);
        m_sprite_.setTexture(m_texture_);

        int height = m_texture_.getSize().y;
        int width = m_texture_.getSize().x;
        m_sprite_.setTextureRect(sf::IntRect(sf::Vector2i{}, sf::Vector2i{width, height}));

        CenterPivot();
    }

    sf::Texture Actor::GetTextureFromPath(const std::string& texturePath)
    {
        return *AssetManager::Get().LoadTexture(texturePath);
    }

    void Actor::SetActorLocation(const sf::Vector2f& new_location)
    {
        m_sprite_.setPosition(new_location);
    }

    void Actor::SetActorRotation(const sf::Angle& new_rotation)
    {
        m_sprite_.setRotation(new_rotation);
    }

    void Actor::SetActorLocationOffset(const sf::Vector2f& offset_amount)
    {
        m_sprite_.setPosition(GetActorLocation() + offset_amount);
    }

    void Actor::SetActorRotationOffset(const sf::Angle& offset_amount)
    {
        m_sprite_.setRotation(m_sprite_.getRotation() + offset_amount);
    }

    sf::Vector2f Actor::GetActorLocation() const
    {
        return m_sprite_.getPosition();
    }

    float Actor::GetActorRotation() const
    {
        return m_sprite_.getRotation().asDegrees();
    }

    sf::Vector2f Actor::GetActorForwardDirection() const
    {
        return RotationToVector(GetActorRotation());
    }

    sf::Vector2f Actor::GetActorRightDirection() const
    {
        return RotationToVector(GetActorRotation() + 90.f);
    }

    void Actor::CenterPivot()
    {
        sf::FloatRect bound = GetBounds();
        m_sprite_.setOrigin(sf::Vector2f(bound.size.x / 2, bound.size.y / 2));
    }
}
