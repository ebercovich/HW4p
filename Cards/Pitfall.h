//
// Created by eyalb on 13/06/2022.
//

#ifndef HW4_PITFALL_H
#define HW4_PITFALL_H

#include "Card.h"

class Pitfall : public Card {
public:
    Pitfall();

    Pitfall(const Pitfall &) = default;

    ~Pitfall() override = default;

    Pitfall &operator=(const Pitfall &) = delete;

    static void fall(Player &);

    void applyEncounter(Player &player) override;

};

#endif //HW4_PITFALL_H
