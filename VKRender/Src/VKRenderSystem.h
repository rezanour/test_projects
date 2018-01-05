#pragma once

#include <VKRender.h>

#include <vulkan.h>

namespace test_projects {
    class VKRenderSystem : public IVKRenderSystem {
    public:
        VKRenderSystem() = default;
        virtual ~VKRenderSystem();

        bool Initialize();

    private:
        VkInstance                 instance_          = nullptr;
        VkPhysicalDevice           physical_device_   = nullptr;
        VkPhysicalDeviceProperties device_properties_ = {0};
    };
} // namespace test_projects
