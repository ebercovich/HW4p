//
// Created by eyalb on 13/06/2022.
//

#ifndef HW4_TREASURE_H
#define HW4_TREASURE_H

#include "Card.h"

class Treasure : public Card {
public:
    Treasure();

    Treasure(const Treasure &) = default;

    ~Treasure() override = default;

    Treasure &operator=(const Treasure &) = delete;

    static void open(Player &);

    void applyEncounter(Player &) override;
};

#endif //HW4_TREASURE_H
