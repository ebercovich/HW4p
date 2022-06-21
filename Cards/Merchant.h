//
// Created by eyalb on 13/06/2022.
//

#ifndef HW4_MERCHANT_H
#define HW4_MERCHANT_H

#include "Card.h"

class Merchant : public Card {
public:
    Merchant();

    Merchant(const Merchant &) = default;

    ~Merchant() override = default;

    Merchant &operator=(const Merchant &) = delete;

    static bool buyHP(Player &);

    static bool buyForce(Player &);

    void applyEncounter(Player &player) override;

};

#endif //HW4_MERCHANT_H
