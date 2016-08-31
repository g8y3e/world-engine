#pragma once

#include <world_base/game.h>

namespace test_game {
    class TestGame : public world_base::Game {
    public:
        TestGame();
        virtual ~TestGame();
    };
}