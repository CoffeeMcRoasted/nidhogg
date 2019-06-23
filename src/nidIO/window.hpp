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
    Window(uint32_t width, uint32_t height);
    uint32_t width_;
    uint32_t height_;
};
using WindowPtr = std::shared_ptr<Window>;

// SFINAE adaptation to concepts
template <typename W>
struct has_static_function_Delete
{
private:
    template <typename T>
    static constexpr auto check()
        -> typename std::is_same<
            decltype(T::Delete(W *)),
            Ret>::type;

    template <typename>
    static constexpr std::false_type check(...);

    typedef decltype(check<C>(0)) type;

public:
    static constexpr bool value = type::value;
};

template <typename W>
struct WindowCreateHelper
{
    static WindowPtr CreateWindow(uint32_t width = 600u, uint32_t height = 400u)
    {
        static_assert(std::is_base_of<Window, W>::value, "Window Create can only be used with classes of inherited from nidhogg::io::Window");
        return WindowPtr(W(width, height), [=](W *window) {W::Delete();
        delete window; });
    }
};

} // namespace io
} // namespace nidhogg

nidhogg::io::WindowPtr nidhogg::io::WindowCreateHelper<typename W>::CreateWindow(uint32_t width, uint32_t height)
{
    static_assert(std::is_base_of<Window, W>::value, "Window Create can only be used with classes of inherited from nidhogg::io::Window");
    return nidhogg::io::WindowPtr(W(width, height), W::Delete)
}

#endif // !_NID_IO_WINDOW_HPP_