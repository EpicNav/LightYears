#include "framework/Application.h"
#include "framework/AssetManager.h"
#include "framework/World.h"

namespace ly
{
    Application::Application(sf::Vector2u window_size, std::string window_title)
        : m_window_(sf::VideoMode(window_size), window_title)
        , m_target_frame_rate_(120.f)
        , m_tick_clock_()
        , m_current_world_(nullptr)
        , m_clean_cycle_clock_()
        , m_clean_cycle_interval_(2.1f)
    {
    }

    void Application::Run()
    {
        m_tick_clock_.restart();
        float accumulatedTime = 0.f;
        float targetDeltaTime = 1.f / m_target_frame_rate_;
        
        while (m_window_.isOpen())
        {
            while (const std::optional<sf::Event> event = m_window_.pollEvent())
            {
                if (event->is<sf::Event::Closed>())
                {
                    m_window_.close();
                }
            }

            float frame_delta_time = m_tick_clock_.restart().asSeconds();
            accumulatedTime += frame_delta_time;
            while (accumulatedTime > targetDeltaTime)
            {
                accumulatedTime -= targetDeltaTime;

                TickInternal(targetDeltaTime);
            }
            
            RenderInternal();
        }
    }

    void Application::TickInternal(float DeltaTime)
    {
        Tick(DeltaTime);
        
        if (m_current_world_)
        {
            m_current_world_->TickInternal(DeltaTime);
        }

        if (m_clean_cycle_clock_.getElapsedTime().asSeconds() >= m_clean_cycle_interval_)
        {
            m_clean_cycle_clock_.restart();
            AssetManager::Get().CleanCycle();
        }
    }

    void Application::Tick(float DeltaTime)
    {
    }

    void Application::RenderInternal()
    {
        m_window_.clear();

        Render();
        
        m_window_.display();
    }

    void Application::Render()
    {
        if (m_current_world_)
        {
            m_current_world_->Render(m_window_);
        }
    }
}
