#include "framework/Actor.h"
#include "framework/Core.h"

namespace ly
{
    Actor::Actor(World* owning_world)
        : m_owning_world_(nullptr)
        , m_begin_play_(false)
    {
    }

    Actor::~Actor()
    {
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
        Tick(DeltaTime);
    }

    void Actor::BeginPlay()
    {
        LOG("Actor Begin Play");
    }

    void Actor::Tick(float DeltaTime)
    {
        LOG("Actor is Ticking");
    }
}
