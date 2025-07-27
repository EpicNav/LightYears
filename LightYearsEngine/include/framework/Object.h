#pragma once
#include <memory>

namespace ly
{
    class Object : public std::enable_shared_from_this<Object>
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
