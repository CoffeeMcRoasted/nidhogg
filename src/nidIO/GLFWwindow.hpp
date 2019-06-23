#ifndef _NID_IO_GLFW_WINDOW_HPP_
#define _NID_IO_GLFW_WINDOW_HPP_

#include "window.hpp"
#include <glfw/glfw3.h>
namespace nidhogg
{
namespace io
{
class GLFWWindow : public Window, public WindowCreateHelper<GlFWWindow>
{
    friend struct WindowCreateHelper<GLFWWindow>;

public:
    std::pair<uint32_t, char const *const[]> getRequiredExtensions() final;

protected:
    GLFWWindow(uint32_t width, uint32_t height);
};
} // namespace io
} // namespace nidhogg

#endif _NID_IO_GLFW_WINDOW_HPP_