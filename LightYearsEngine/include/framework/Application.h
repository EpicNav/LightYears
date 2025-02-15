#pragma once

#include <SFML/Graphics.hpp>

#include "World.h"
#include "framework/Core.h"

namespace ly
{
    class World;
    class Application
    {
    public:
        Application(sf::Vector2u window_size = sf::Vector2u(768, 1080) /** Default size */, std::string window_title);

        void Run();
        void RenderInternal();
        void TickInternal(float DeltaTime);

        template<typename T>
        TWeakPtr<T> LoadWorld();

    protected:
        virtual void Tick(float DeltaTime);
        virtual void Render();

    private:
        sf::RenderWindow m_window_;
        float m_target_frame_rate_;
        sf::Clock m_tick_clock_;

        TSharedPtr<World> m_current_world_;
    };

    template<typename WorldType>
    TWeakPtr<WorldType> Application::LoadWorld()
    {
        TSharedPtr<WorldType> newWorld(new WorldType(this));
        m_current_world_ = newWorld;
        m_current_world_->BeginPlayInternal();
        return newWorld;
    }
}
