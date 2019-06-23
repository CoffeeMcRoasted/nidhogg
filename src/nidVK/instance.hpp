#ifndef _NID_VK_INSTANCE_HPP_
#define _NID_VK_INSTANCE_HPP_
#include <vulkan/vulkan.h>
#include <memory>
#include <functional>
namespace nidhogg
{
namespace vk
{
struct Instance
{
    VkInstance ptr = nullptr;
    VkAllocationCallbacks const *allocation_callback_ptr = nullptr;
    VkInstanceCreateInfo create_info;
    VkApplicationInfo application_info;
    static InstancePtr Create(const VkApplicationInfo &appInfo, VkAllocationCallbacks const *alloc_ptr = nullptr);

private:
    Instance(const VkApplicationInfo &app_info, VkAllocationCallbacks const *alloc_ptr);
};

using InstancePtr = std::unique_ptr<Instance, std::function<void(Instance *)>>;

}; // namespace vk
}; // namespace nidhogg

#endif // !_NID_VK_INSTANCE_HPP_