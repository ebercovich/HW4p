//
// Created by Nir on 6/12/2022.
//
#include "Card.h"
#include "../Exception.h"
#include "../utilities.h"

Card::Card(const std::string &playerName) {
    if (playerName.length() > 15 || !isInEnglish(playerName)) {
        throw InputStringException();
    }

    this->m_name = playerName;
}

const std::string &Card::getName() const {
    return this->m_name;
}

std::ostream& operator<<(std::ostream& ostream,const Card& card){
    card.printInfo(ostream);
    return ostream;
}

void Card::printInfo(ostream& os) const {
    printCardDetails(os,this->getName());
    printEndOfCardDetails(os);
}

