#include "../../includes.hpp"

template <typename T>
static constexpr auto relativeToAbsolute(std::uintptr_t address) noexcept
{
    return (T)(address + 4 + *reinterpret_cast<std::int32_t*>(address));
}

int Hooks::PollEvent(SDL_Event* event) {
    const auto result = pollEvent(event);

    if (Menu::initialised) {
        Menu::onPollEvent(event, result);
    }

    return result;
}

void Hooks::SwapWindow(SDL_Window* window) {
    Menu::onSwapWindow(window);
    swapWindow(window);
}

void Hooks::initSDL() {
    Log::log("initialising OpenGL Hooks...");
    const auto libSDL = dlopen("libSDL2-2.0.so.0", RTLD_LAZY | RTLD_NOLOAD);

    swapWindowAddr = relativeToAbsolute<uintptr_t>(uintptr_t(dlsym(libSDL, "SDL_GL_SwapWindow")) + 3);
    swapWindow = *reinterpret_cast<decltype(swapWindow)*>(swapWindowAddr);
    *reinterpret_cast<decltype(SwapWindow)**>(swapWindowAddr) = SwapWindow;

    pollEventAddr = relativeToAbsolute<uintptr_t>(uintptr_t(dlsym(libSDL, "SDL_PollEvent")) + 3);
    pollEvent = *reinterpret_cast<decltype(pollEvent)*>(pollEventAddr);
    *reinterpret_cast<decltype(PollEvent)**>(pollEventAddr) = PollEvent;

    Log::log(std::string("swapwindow >> ") + std::to_string(swapWindowAddr));
}

void Hooks::unloadSDL() {
    Log::log("unloading OpenGL Hooks...");
    *reinterpret_cast<decltype(pollEvent)*>(swapWindowAddr) = pollEvent;
    *reinterpret_cast<decltype(swapWindow)*>(swapWindowAddr) = swapWindow;
}