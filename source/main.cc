#include <world_base/debug/log.h>
#include <world_base/game.h>

#include<iostream>

int main(int argc, char** argv) {
	
    std::cout << "test before" << std::endl;

    world_base::debug::LOGINFO("test info");
    world_base::debug::LOGWARN("test warning");
    world_base::debug::LOGERROR("test error");
    world_base::debug::LOGCONFIG("test config");

    std::cout << "test after" << std::endl;

    world_base::Game game;

    game.init("Test Wolrd");

    std::cin.get();
    return game.run();
}