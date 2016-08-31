#pragma once

#include <third_party/sdl2/SDL.h>

namespace world_base {
    class Render {
    public:
        void init();

    protected:
        SDL_Window* window_;
        SDL_GLContext context_;
    };
}