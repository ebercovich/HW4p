//
// Created by Nir on 6/12/2022.
//

#ifndef HW4_CARD_H
#define HW4_CARD_H

#include <string>
#include "../Players/Player.h"

class Card {

public:
    explicit Card(const std::string &name);

    Card(const Card &) = default;

    virtual ~Card() = default;

    Card &operator=(const Card &) = delete;

    const std::string &getName() const;

    virtual void applyEncounter(Player &player) = 0;

    friend std::ostream &operator<<(std::ostream &ostream, const Card &card);

    virtual void printInfo(std::ostream &os) const;


protected:
    std::string m_name;
};


#endif //HW4_CARD_H
