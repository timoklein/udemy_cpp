#include "Player.h"
#include <iostream>

// Initialize static class member here
int Player::num_players {0};

Player::Player(std::string name_val, int health_val, int xp_val)
    : name {name_val}, health {health_val}, xp {xp_val} {
        ++num_players;
}

Player::Player(const Player &source)
    : Player {source.name, source.health, source.xp} {
        std::cout << "Player copied" << std::endl;
}

Player::~Player(){
        --num_players;
}

// Define static methods here
int Player::get_num_players() {
    return num_players;
}
