//
// Created by Nir on 6/12/2022.
//
#include "Fighter.h"
#include "iostream"

Fighter::Fighter(const std::string &playerName) : Player(playerName,"Fighter") {}

Fighter::Fighter(const std::string &playerName, int maxHP) : Player(playerName,"Fighter", maxHP) {}

Fighter::Fighter(const std::string &playerName, int maxHP, int initialForce) :
        Player(playerName,"Fighter", maxHP, initialForce) {}

int Fighter::getAttackStrength() const {
    return 2 * this->m_force + this->m_level;
}

