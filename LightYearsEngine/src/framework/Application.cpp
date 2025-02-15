#include <stdio.h>
#include "framework/Application.h"

#include "framework/Core.h"
#include "framework/World.h"

namespace ly
{
    Application::Application(sf::Vector2u window_size, std::string window_title)
        : m_window_(sf::VideoMode(window_size), window_title)
        , m_target_frame_rate_(120.f)
        , m_tick_clock_()
        , m_current_world_(nullptr)
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
        sf::RectangleShape rect(sf::Vector2f(100, 100));
        rect.setPosition(sf::Vector2f(m_window_.getSize().x / 2, m_window_.getSize().y / 2));
        rect.setOrigin(sf::Vector2f(50, 50));
        rect.setFillColor(sf::Color::Magenta);
        m_window_.draw(rect);
    }
}
