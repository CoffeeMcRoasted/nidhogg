#include "instance.hpp"

namespace nidhogg
{
namespace vk
{

InstancePtr Instance::create(const VkApplicationInfo &appInfo, VkAllocationCallbacks const *allocP)
{
    return InstancePtr(new Instance(appInfo, allocP), [](Instance *p) { vkDestroyInstance(p->ptr, p->alloc); });
}

Instance::Instance(const VkApplicationInfo &appInfo, VkAllocationCallbacks const *allocP)
    : aInfo(appInfo), alloc(allocP)
{
    cInfo.pApplicationInfo = &aInfo;
    cInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    // Extension count for interfacing with the window system
    // getExtensionData
    // cInfo.enabledExtensionCount = data;
    // cInfo.ppEnabledExtensionNames = names;
    VkResult res = vkCreateInstance(&cInfo, allocP, &ptr);
    if (res != VK_SUCCESS)
    {
        ptr = nullptr;
    }
}
} // namespace vk
} // namespace nidhogg