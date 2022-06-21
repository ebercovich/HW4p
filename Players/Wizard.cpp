//
// Created by eyalb on 13/06/2022.
//
#include <string>
#include "Wizard.h"
#include "../Exception.h"

Wizard::Wizard(const string &playerName) : Player(playerName, "Wizard") {}

Wizard::Wizard(const string &playerName, int maxHP) : Player(playerName, "Wizard", maxHP) {}

Wizard::Wizard(const string &playerName, int maxHP, int initialForce) : Player(playerName, "Wizard", maxHP,
                                                                               initialForce) {}

void Wizard::heal(int hpAddition) {
    if (hpAddition < 0) {
        throw NonPositive(false);
    }
    if (this->m_HP + 2 * hpAddition >= this->m_maxHP) {
        this->m_HP = this->m_maxHP;
    } else
        this->m_HP += 2 * hpAddition;
}

