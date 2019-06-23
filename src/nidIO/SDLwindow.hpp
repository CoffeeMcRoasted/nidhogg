#ifndef _NID_IO_SDL_WINDOW_HPP_
#define _NID_IO_SDL_WINDOW_HPP_

#include "window.hpp"
namespace nidhogg
{
namespace io
{
class SDLWindow : public Window, public WindowCreateHelper<SDLWindow>
{
    std::pair<uint32_t, char const *const []> getRequiredExtensions() final {};
};
} // namespace io
} // namespace nidhogg

#endif // !_NID_IO_SDL_WINDOW_HPP__