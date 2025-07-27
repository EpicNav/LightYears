#pragma once

#include "framework/Object.h"
#include "framework/Core.h"
#include "SFML/Graphics.hpp"

namespace ly
{
    class World;
    
    class Actor : public Object
    {
    public:
        Actor(World* owning_world, const std::string& texturePath = "");
        virtual ~Actor();

        void BeginPlayInternal();
        void TickInternal(float DeltaTime);
        void Render(sf::RenderWindow &InWindow);
        void SetTextureFromPath(const std::string& texturePath);
        sf::Texture GetTextureFromPath(const std::string& texturePath);

        void SetActorLocation(const sf::Vector2f& new_location);
        void SetActorRotation(const sf::Angle& new_rotation);
        void SetActorLocationOffset(const sf::Vector2f& offset_amount);
        void SetActorRotationOffset(const sf::Angle& offset_amount);

        sf::Vector2f GetActorLocation() const;
        float GetActorRotation() const;
        sf::Vector2f GetActorForwardDirection() const;
        sf::Vector2f GetActorRightDirection() const;
        void CenterPivot();

        sf::Sprite GetSprite() const { return m_sprite_; }
        sf::FloatRect GetBounds() const { return m_sprite_.getGlobalBounds(); }

    protected:
        virtual void BeginPlay();
        virtual void Tick(float DeltaTime);

    private:
        TSharedPtr<World> m_owning_world_;
        bool m_begin_play_;

        sf::Sprite m_sprite_;
        sf::Texture m_texture_;

        std::string m_texture_path_;
    };
}
