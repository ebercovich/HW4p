//
// Created by eyalb on 13/06/2022.
//

#ifndef HW4_BATTLE_H
#define HW4_BATTLE_H

#include <string>
#include "Card.h"

class Battle : public Card {
public:

    Battle(const std::string &, int, int, int);

    Battle(const Battle &) = default;

    ~Battle() override = default;

    Battle &operator=(const Battle &) = delete;

    //** returns true if the player won
    virtual bool fight(Player &);

    void applyEncounter(Player &player) override;

    void printInfo(std::ostream &os) const override;

    friend class Gang;

protected:
    int m_force;
    int m_loot;
    int m_damage;
};

#endif //HW4_BATTLE_H
