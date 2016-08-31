#pragma once

#include <memory>

#include "render/render.h"

namespace world_base {
    class Game {
    public:
        Game();
        virtual ~Game();
        
    public:
        virtual void init();
        int run();

    protected:
        std::unique_ptr<Render> render_;
    };
}