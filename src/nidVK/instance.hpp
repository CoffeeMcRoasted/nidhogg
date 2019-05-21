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
    VkAllocationCallbacks const *alloc = nullptr;
    VkInstanceCreateInfo cInfo;
    VkApplicationInfo aInfo;
    static InstancePtr create(const VkApplicationInfo &appInfo, VkAllocationCallbacks const *allocP = nullptr);

private:
    Instance(const VkApplicationInfo &appInfo, VkAllocationCallbacks const *allocP);
};

using InstancePtr = std::unique_ptr<Instance, std::function<void(Instance *)>>;

}; // namespace vk
}; // namespace nidhogg

#endif // !_NID_VK_INSTANCE_HPP_