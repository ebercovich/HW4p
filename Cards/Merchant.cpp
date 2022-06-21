//
// Created by eyalb on 13/06/2022.
//

#include "Merchant.h"
#include "../utilities.h"

Merchant::Merchant() : Card("Merchant") {}

bool Merchant::buyHP(Player &player) {
    if (player.pay(5)) {
        player.heal(1);
        return true;
    }
    return false;
}

bool Merchant::buyForce(Player &player) {
    if (player.pay(10)) {
        player.buff(1);
        return true;
    }
    return false;
}

void Merchant::applyEncounter(Player &player) {
    int choice;
    printMerchantInitialMessageForInteractiveEncounter(cout, player.getName(), player.getCoins());
    cin >> choice;
    while (choice != 0 && choice != 1 && choice != 2) {
        printInvalidInput();
    }
    if (choice == 1) {
        if (buyHP(player)) {
            printMerchantSummary(cout, player.getName(), choice, 5);
            return;
        }
        if (!buyHP(player)) {
            printMerchantInsufficientCoins(cout);
            return;
        }
    }
    if (choice == 2) {
        if (buyForce(player)) {
            printMerchantSummary(cout, player.getName(), choice, 10);
            return;
        }
        if (!buyForce(player)) {
            printMerchantInsufficientCoins(cout);
            return;
        }
    }
    if (choice == 0) {
        printMerchantSummary(cout, player.getName(), choice, 0);
    }
}