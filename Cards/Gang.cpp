//
// Created by eyalb on 19/06/2022.
//
#include <vector>
#include "../Exception.h"
#include "Battle.h"
#include "Vampire.h"
#include "Dragon.h"
#include "Goblin.h"
#include "Gang.h"
#include "../utilities.h"

Gang::Gang() : Card("Gang") {}

void Gang::pushEnemy(const std::string &enemy, int lineInfile) {
    if (enemy == "Goblin") {
        this->m_enemies.push_back(unique_ptr<Battle>(new Goblin()));
    } else if (enemy == "Vampire") {
        this->m_enemies.push_back(unique_ptr<Battle>(new Vampire()));
    } else if (enemy == "Dragon") {
        this->m_enemies.push_back(unique_ptr<Battle>(new Dragon()));
    } else throw DeckFileFormatError(lineInfile);
}

bool Gang::fight(Player &player) {
    for (vector<unique_ptr<Battle>>::iterator enemy = m_enemies.begin(); enemy != m_enemies.end(); ++enemy) {
        if (player.getAttackStrength() < enemy->get()->m_force) {
            this->lose(player, enemy);
            return false;
        }
        player.addCoins(enemy->get()->m_loot);

    }
    player.levelUp();
    printWinBattle(player.getName(), this->getName());
    return true;
}

void Gang::lose(Player &player, vector<unique_ptr<Battle>>::iterator enemy) {
    while (enemy != m_enemies.end()) {
        printLossBattle(player.getName(), enemy->get()->getName());
        if (enemy->get()->getName() == "Vampire") {
            player.nerf(1);
        }
        player.damage(enemy->get()->m_damage);
        ++enemy;
    }
}

void Gang::applyEncounter(Player &player) {
    this->fight(player);
}

void Gang::printInfo(std::ostream &os) const {
    printCardDetails(os, this->m_name);
    for (const unique_ptr<Battle> &enemy: m_enemies) {
        enemy->printInfo(os);
    }
    printEndOfCardDetails(os);
}