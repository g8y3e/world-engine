#include "game.h"
#include "debug/log.h"
#include "helper/define.h"

#include <string>

namespace world_base {
    Game::Game() {
    }

    Game::~Game() {
    }

    void Game::init() {
        render_->init();
    }

    int Game::run() {
        debug::LOGCONFIG("Run game loop!");
        return 0;
    }
}