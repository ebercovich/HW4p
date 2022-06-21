//
// Created by eyalb on 13/06/2022.
//

#include "Battle.h"
#include "../utilities.h"

Battle::Battle(const std::string &playerName, int force, int loot, int damage) :
        Card(playerName), m_force(force), m_loot(loot), m_damage(damage) {}

bool Battle::fight(Player &player) {
    if (player.getAttackStrength() < this->m_force) {
        player.damage(this->m_damage);
        return false;
    }
    player.levelUp();
    player.addCoins(this->m_loot);
    return true;
}

void Battle::applyEncounter(Player &player) {
    if (this->fight(player)) {
        printWinBattle(player.getName(), this->getName());
    } else {
        printLossBattle(player.getName(), this->getName());
    }
}

void Battle::printInfo(std::ostream &os) const {
    bool isDragon = (this->m_name == "Dragon");
    printCardDetails(os, this->m_name);
    printMonsterDetails(os, this->m_force, this->m_damage, this->m_loot, isDragon);
    printEndOfCardDetails(os);
}