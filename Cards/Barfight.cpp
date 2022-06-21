//
// Created by eyalb on 13/06/2022.
//
#include "Barfight.h"
#include "../Players/Fighter.h"
#include "../utilities.h"

Barfight::Barfight() : Card("Barfight") {}

void Barfight::brawl(Player &player) {
    if (player.getType() != "Fighter") {
        player.damage(10);
    }
}

void Barfight::applyEncounter(Player &player) {
    this->brawl(player);
    bool isFighter = (player.getType() == "Fighter");
    printBarfightMessage(isFighter);
}