//
// Created by eyalb on 13/06/2022.
//
#include "Treasure.h"
#include "../utilities.h"

Treasure::Treasure() : Card("Treasure") {}

void Treasure::open(Player &player) {
    player.addCoins(10);
}

void Treasure::applyEncounter(Player &player) {
    this->open(player);
    printTreasureMessage();
}