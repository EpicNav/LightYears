#include "framework/Object.h"
#include "framework/Core.h"

namespace ly
{
    Object::Object()
        : m_is_pending_kill_(false)
    {
    }

    Object::~Object()
    {
    }

    void Object::DestroyInternal()
    {
        Destory();
    }

    void Object::Destory()
    {
        m_is_pending_kill_ = true;

        LOG("Object Destroyed");
    }
}
