#include "VKRenderSystem.h"
#include <TPLog.h>

#include <vector>

namespace test_projects {
    VKRenderSystem::~VKRenderSystem() {
        if (physical_device_) {
            physical_device_ = nullptr;
        }

        if (instance_) {
            vkDestroyInstance(instance_, nullptr);
            instance_ = nullptr;
        }
    }

    bool VKRenderSystem::Initialize() {
        VkApplicationInfo app_info{};
        app_info.sType       = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        app_info.pEngineName = "VKRenderer";

        VkInstanceCreateInfo instance_create_info{};
        instance_create_info.sType                 = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        instance_create_info.enabledExtensionCount = 0;
        instance_create_info.enabledLayerCount     = 0;
        instance_create_info.pApplicationInfo      = &app_info;
        VkResult result = vkCreateInstance(&instance_create_info, nullptr, &instance_);
        if (VK_SUCCESS != result) {
            return false;
        }

        uint32_t count = 0;
        result = vkEnumeratePhysicalDevices(instance_, &count, nullptr);
        if (VK_SUCCESS != result) {
            return false;
        }

        std::vector<VkPhysicalDevice> devices(count);
        result = vkEnumeratePhysicalDevices(instance_, &count, devices.data());
        if (VK_SUCCESS != result) {
            return false;
        }

        for (auto &device : devices) {
            VkPhysicalDeviceProperties props{};
            vkGetPhysicalDeviceProperties(device, &props);

            if (VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU == props.deviceType) {
                // choose this device
                physical_device_   = device;
                device_properties_ = props;
                break;
            }
        }

        if (!physical_device_) {
            return false;
        }

        TPLOG("Device Selected: %s\n", device_properties_.deviceName);

        return true;
    }
} // namespace test_projects
