#include <world_base/debug/log.h>
#include <test_game/test_game.h>

#include<iostream>

#include <string>
#include <third_party/sdl2/SDL.h>

int main(int argc, char** argv) {
    SDL_Log("");

    std::cout << "test before" << std::endl;

    world_base::debug::LOGINFO("test info");
    world_base::debug::LOGWARN("test warning");
    world_base::debug::LOGERROR("test error");
    world_base::debug::LOGCONFIG("test config");

    std::cout << "test after" << std::endl;

    test_game::TestGame game;

    game.init();

    std::cin.get();
    return game.run();
}