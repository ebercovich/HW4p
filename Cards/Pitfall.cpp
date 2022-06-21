//
// Created by eyalb on 13/06/2022.
//
#include "Pitfall.h"
#include "../Players/Rogue.h"
#include "../utilities.h"


Pitfall::Pitfall() : Card("Pitfall") {}

void Pitfall::fall(Player &player) {
    if (player.getType() != "Rogue") {
        player.damage(10);
    }
}

void Pitfall::applyEncounter(Player &player) {
    this->fall(player);
    bool isRogue = (player.getType() == "Rogue");
    printPitfallMessage(isRogue);
}