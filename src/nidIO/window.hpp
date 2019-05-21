#ifndef _NID_IO_WINDOW_HPP_
#define _NID_IO_WINDOW_HPP_
#include <utility>
#include <memory>
#include <type_traits>
#include <cstdint>
namespace nidhogg
{
namespace io
{
class Window
{
public:
    virtual std::pair<uint32_t, char const *const[]> getRequiredExtensions() = 0;
    virtual ~Window();

    Window(const Window &w) = delete;
    Window &operator=(Window const &w) = delete;

    Window(Window &&w) = default;
    Window &operator=(Window &&w) = default;

protected:
    Window(uint32_t width, uint32_t heigth);
    uint32_t width;
    uint32_t height;
};
using WindowPtr = std::shared_ptr<Window>;

template <typename W>
struct WindowCreateHelper
{
    static WindowPtr createWindow(uint32_t width = 600u, uint32_t height = 400u)
    {
        static_assert(std::is_base_of<Window, W>::value, "Window Create can only be used with classes of inherited from nidhogg::io::Window");
        return WindowPtr(W(width, height), )
    }
};

} // namespace io
} // namespace nidhogg

#endif // !_NID_IO_WINDOW_HPP_