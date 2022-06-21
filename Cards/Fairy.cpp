//
// Created by eyalb on 13/06/2022.
//
#include "../Players/Wizard.h"
#include "Fairy.h"
#include "../utilities.h"

Fairy::Fairy() : Card("Fairy") {}

void Fairy::fairyDust(Player &player) {
    if (player.getType() == "Wizard") {
        player.heal(10);
    }
}

void Fairy::applyEncounter(Player &player) {
    this->fairyDust(player);
    bool isWizard (player.getType() == "Wizard");
    printFairyMessage(isWizard);
}