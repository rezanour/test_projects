#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <VKRender.h>

#ifdef _WIN32
int WINAPI WinMain(HINSTANCE instance, HINSTANCE prev_instance, LPSTR command_line, int show_command) {
#endif

#ifdef _WIN32
    UNREFERENCED_PARAMETER(instance);
    UNREFERENCED_PARAMETER(prev_instance);
    UNREFERENCED_PARAMETER(command_line);
    UNREFERENCED_PARAMETER(show_command);
#endif

    std::shared_ptr<test_projects::IVKRenderSystem> render_system;
    if (!test_projects::IVKRenderSystem::Create(render_system)) {
        return -1;
    }

    render_system.reset();
    return 0;
}