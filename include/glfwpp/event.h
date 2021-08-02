#ifndef GLFWPP_EVENT_H
#define GLFWPP_EVENT_H

#include <GLFW/glfw3.h>
#include <functional>
#include <list>

namespace glfw
{
    template<typename... Args>
    class Event
    {
    private:
        std::function<void(Args...)> _handler;

    public:
        template<typename CallbackT>
        void setCallback(CallbackT&& callback_)
        {
            _handler = std::forward<CallbackT>(callback_);
        }
        void operator()(Args... args_)
        {
            if(_handler)
            {
                _handler(args_...);
            }
        }
    };

    [[gnu::always_inline]] inline void pollEvents()
    {
        glfwPollEvents();
    }

    [[gnu::always_inline]] inline void waitEvents()
    {
        glfwWaitEvents();
    }
    [[gnu::always_inline]] inline void waitEvents(double timeout_)
    {
        glfwWaitEventsTimeout(timeout_);
    }

    [[gnu::always_inline]] inline void postEmptyEvent()
    {
        glfwPostEmptyEvent();
    }
}  // namespace glfw

#endif  //GLFWPP_EVENT_H
