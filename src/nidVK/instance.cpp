#include "instance.hpp"

namespace nidhogg
{
namespace vk
{

InstancePtr Instance::Create(const VkApplicationInfo &app_info, VkAllocationCallbacks const *allocation_callback_ptr)
{
    return InstancePtr(new Instance(app_info, allocation_callback_ptr), [](Instance *p) { vkDestroyInstance(p->ptr, p->allocation_callback_ptr); });
}

Instance::Instance(const VkApplicationInfo &app_info, VkAllocationCallbacks const *allocation_callback_ptr)
    : application_info(app_info), allocation_callback_ptr(allocation_callback_ptr)
{
    create_info.pApplicationInfo = &application_info;
    create_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    // Extension count for interfacing with the window system
    // getExtensionData
    // cInfo.enabledExtensionCount = data;
    // cInfo.ppEnabledExtensionNames = names;
    VkResult result = vkCreateInstance(&create_info, allocation_callback_ptr, &ptr);
    if (result != VK_SUCCESS)
    {
        ptr = nullptr;
    }
}
} // namespace vk
} // namespace nidhogg