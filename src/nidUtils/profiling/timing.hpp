#ifndef _NID_UTILS_TIMING_HPP_
#define _NID_UTILS_TIMING_HPP_
#include <chrono>
namespace nidhogg
{
namespace utils
{
template <typename TimeT = std::chrono::milliseconds>
struct Measure
{
    template <typename F, typename... Args>
    static auto Duration(F &&func, Args &&... args)
    {
        auto start = std::chrono::steady_clock::now();
        std::forward<decltype(func)>(func)(std::forward<Args>(args)...);
        return std::chrono::duration_cast<TimeT>(std::chrono::steady_clock::now() - start);
    }
};
} // namespace utils
} // namespace nidhogg

#endif // !_NID_UTILS_TIMING_HPP_