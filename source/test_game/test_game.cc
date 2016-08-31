#include "test_game.h"

namespace test_game {
    TestGame::TestGame() {
        render_.reset(new world_base::Render());
    }

    TestGame::~TestGame() {
    }
}