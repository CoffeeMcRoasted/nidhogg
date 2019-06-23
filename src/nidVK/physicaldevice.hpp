#ifndef _NID_VK_PHYSICAL_DEVICE_HPP_
#define _NID_VK_PHYSICAL_DEVICE_HPP_
#include <vulkan/vulkan.h>
#include <memory>

namespace nidhogg
{
namespace vk
{
struct PhysicalDevice
{
    VkPhysicalDevice ptr = VK_NULL_HANDLE;
    VkPhysicalDeviceProperties properties;

private:
    PhysicalDevice();
};
int BasicRateDeviceSuitability(VkPhysicalDevice device);
PhysicalDevice PickPhysicalDevice(int (*physicalDeviceFilter)(VkPhysicalDevice &p) = &BasicRateDeviceSuitability);
using PhysicalDevicePtr = std::unique_ptr<PhysicalDevice>;
} // namespace vk
} // namespace nidhogg

#endif // !_NID_VK_PHYSICAL_DEVICE_HPP_