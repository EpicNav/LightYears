#pragma once

#include "framework/Object.h"
#include "framework/Core.h"

namespace ly
{
    class World;
    
    class Actor : public Object
    {
    public:
        Actor(World* owning_world);
        virtual ~Actor();

        void BeginPlayInternal();
        void TickInternal(float DeltaTime);

    protected:
        virtual void BeginPlay();
        virtual void Tick(float DeltaTime);

    private:
        TSharedPtr<World> m_owning_world_;
        bool m_begin_play_;
    };
}
