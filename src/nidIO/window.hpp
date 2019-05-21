#ifndef _NID_IO_WINDOW_HPP_
#define _NID_IO_WINDOW_HPP_
#include <utility>
#include <memory>
#include <cstdint>
namespace nidhogg
{
namespace io
{
class Window
{
public:
    virtual WindowPtr createWindow(uint32_t width = 600u, uint32_t height = 400u) = 0;
    virtual std::pair<uint32_t, char const *const[]> getRequiredExtensions() = 0;
};
using WindowPtr = std::shared_ptr<Window>;

} // namespace io
} // namespace nidhogg

#endif // !_NID_IO_WINDOW_HPP_