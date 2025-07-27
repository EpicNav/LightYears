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
        Application(sf::Vector2u window_size /** Default size */, std::string window_title = "");

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

        sf::Clock m_clean_cycle_clock_;
        float m_clean_cycle_interval_;
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
