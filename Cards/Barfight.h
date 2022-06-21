//
// Created by eyalb on 13/06/2022.
//

#ifndef HW4_BARFIGHT_H
#define HW4_BARFIGHT_H

#include "Card.h"

class Barfight : public Card {
public:
    Barfight();

    Barfight(const Barfight &) = default;

    ~Barfight() override = default;

    Barfight &operator=(const Barfight &) = delete;

    static void brawl(Player &);

    void applyEncounter(Player &player) override;
};

#endif //HW4_BARFIGHT_H
