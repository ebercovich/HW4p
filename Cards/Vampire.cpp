//
// Created by Nir on 6/12/2022.
//

#include "Vampire.h"

Vampire::Vampire() : Battle("Vampire", 10, 2, 10) {}

bool Vampire::fight(Player & player) {
    if (player.getAttackStrength() < this->m_force) {
        player.damage(this->m_damage);
        player.nerf(1);
        return false;
    }
    player.levelUp();
    player.addCoins(this->m_loot);
    return true;
}
