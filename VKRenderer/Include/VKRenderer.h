#pragma once

#include <stdint.h>
#include <memory>

namespace test_projects {
    struct IVKRenderSystem {
        // Creates the RenderSystem. There can only be 1 render system instance in existance at any given time.
        // The render system can be destroyed and recreated if desired.
        // Returns: true if render system was created successfully. false if already exists or creation fails.
        static bool Create(std::shared_ptr<IVKRenderSystem>& out_system);

        virtual ~IVKRenderSystem() {}
    };
} // namespace test_projects
