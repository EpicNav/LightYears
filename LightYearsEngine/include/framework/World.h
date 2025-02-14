#pragma once

namespace ly
{
    class Application;
    
    class World
    {
    public:
        World(Application* InOwningApp);
        virtual ~World();
        
        void BeginPlayInternal();
        void TickInternal(float deltaTime);

    protected:
        virtual void BeginPlay();
        virtual void Tick(float deltaTime);

    private:
        Application* m_OwningApp;
        bool bBeginPlay;
    };
}