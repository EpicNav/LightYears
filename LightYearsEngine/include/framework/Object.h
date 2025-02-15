#pragma once

namespace ly
{
    class Object
    {
    public:
        Object();
        virtual ~Object();

        void DestroyInternal();
        bool IsPendingKill() { return m_is_pending_kill_; }

    protected:
        void Destory();

    private:
        bool m_is_pending_kill_;
    };
}