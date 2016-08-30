#include "game.h"
#include "debug/log.h"

#include <string>

namespace world_base {
    void Game::init(const char* name) {
        std::string init_message = "Init game '";
        init_message.append(name).append("'!");
        debug::LOGCONFIG(init_message);
    }

    int Game::run() {
        debug::LOGCONFIG("Run game loop!");
        return 0;
    }
}