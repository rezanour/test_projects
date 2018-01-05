#include <TPLog.h>
#include <VKRender.h>
#include "VKRenderSystem.h"

namespace test_projects {
    bool IVKRenderSystem::Create(std::shared_ptr<IVKRenderSystem>& out_system) {
        out_system.reset();

        std::shared_ptr<VKRenderSystem> const system = std::make_shared<VKRenderSystem>();
        if (!system->Initialize()) {
            TPLOG(Error, "Failed to initialize VKRenderSystem.");
            return false;
        }

        out_system = system;
        return true;
    }

} // namespace test_projects
