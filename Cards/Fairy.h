//
// Created by eyalb on 13/06/2022.
//

#ifndef HW4_FAIRY_H
#define HW4_FAIRY_H

#include "Card.h"

class Fairy : public Card {
public:
    Fairy();

    Fairy(const Fairy &) = default;

    ~Fairy() override = default;

    Fairy &operator=(const Fairy &) = delete;

    static void fairyDust(Player &);

    void applyEncounter(Player &player) override;

};

#endif //HW4_FAIRY_H
