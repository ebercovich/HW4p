//
// Created by eyalb on 13/06/2022.
//
#include <string>
#include "Rogue.h"
#include "../Exception.h"

Rogue::Rogue(const string &playerName) : Player(playerName,"Rogue") {}

Rogue::Rogue(const string &playerName, int maxHP) : Player(playerName,"Rogue", maxHP) {}

Rogue::Rogue(const string &playerName, int maxHP, int initialForce) : Player(playerName,"Rogue", maxHP, initialForce) {}

void Rogue::addCoins(int coinsAddition) {
    if (coinsAddition < 0) {
        throw NonPositive(false);
    }
    this->m_coins += 2*coinsAddition;
}

