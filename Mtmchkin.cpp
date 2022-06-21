//
// Created by Nir on 6/12/2022.
//
#include "Mtmchkin.h"
#include <iostream>
#include <memory>
#include "utilities.h"
#include <fstream>
#include <string>
#include "Exception.h"
#include "Players/Rogue.h"
#include "Players/Fighter.h"
#include "Players/Wizard.h"
#include "Cards/Goblin.h"
#include "Cards/Fairy.h"
#include "Cards/Vampire.h"
#include "Cards/Barfight.h"
#include "Cards/Dragon.h"
#include "Cards/Treasure.h"
#include "Cards/Pitfall.h"
#include "Cards/Merchant.h"
#include "Cards/Gang.h"

Mtmchkin::Mtmchkin(const std::string &fileName) {
    printStartGameMessage();
    this->m_rounds = 0;
    string line;
    ifstream file(fileName);
    if (!file) {
        throw DeckFileNotFound();
    }
    getline(file, line);
    if (line.empty()) {
        throw DeckFileInvalidSize();
    }
    int lineInFile = 0;
    do {
        lineInFile++;
        if (line == "Fairy") {
            this->m_cardDeck.push_back(std::unique_ptr<Card>(new Fairy()));

        } else if (line == "Goblin") {
            this->m_cardDeck.push_back(std::unique_ptr<Card>(new Goblin()));

        } else if (line == "Vampire") {
            this->m_cardDeck.push_back(std::unique_ptr<Card>(new Vampire()));

        } else if (line == "Barfight") {
            this->m_cardDeck.push_back(std::unique_ptr<Card>(new Barfight()));

        } else if (line == "Dragon") {
            this->m_cardDeck.push_back(std::unique_ptr<Card>(new Dragon()));

        } else if (line == "Treasure") {
            this->m_cardDeck.push_back(std::unique_ptr<Card>(new Treasure()));

        } else if (line == "Pitfall") {
            this->m_cardDeck.push_back(std::unique_ptr<Card>(new Pitfall()));

        } else if (line == "Merchant") {
            this->m_cardDeck.push_back(std::unique_ptr<Card>(new Merchant()));

        } else if (line == "Gang") {
            Gang *gang = new Gang();
            std::getline(file, line);
            lineInFile++;
            while (line != "EndGang") {
                gang->pushEnemy(line, lineInFile);
                if (!std::getline(file, line)) {
                    throw DeckFileFormatError(lineInFile);
                }
                lineInFile++;
            }

            m_cardDeck.push_back(unique_ptr<Card>(gang));
        } else
            throw DeckFileFormatError(lineInFile);
    } while (getline(file, line));


    printEnterTeamSizeMessage();
    int teamSize;
    cin >> teamSize;
    while (teamSize < 2 || teamSize > 6) {
        printInvalidTeamSize();
        cin >> teamSize;
    }
    for (int i = 0; i < teamSize; ++i) {
        printInsertPlayerMessage();
        string playerName, playerType;
        cin >> playerName;
        cin >> playerType;
        while (!isPlayerNameCorrect(playerName) || isPlayerClassCorrect(playerType) == "invalidClass") {
            if (!isPlayerNameCorrect(playerName)) {
                printInvalidName();
                cin >> playerName;
                cin >> playerType;
                continue;
            }
            if (isPlayerClassCorrect(playerType) == "invalidClass") {
                printInvalidClass();
                cin >> playerName;
                cin >> playerType;
            }
        }
        if (isPlayerClassCorrect(playerType) == "Fighter") {
            this->m_PlayersDeque.push_back(std::unique_ptr<Player>(new Fighter(playerName)));
            continue;
        }
        if (isPlayerClassCorrect(playerType) == "Wizard") {
            this->m_PlayersDeque.push_back(std::unique_ptr<Player>(new Wizard(playerName)));
            continue;
        }
        if (isPlayerClassCorrect(playerType) == "Rogue") {
            this->m_PlayersDeque.push_back(std::unique_ptr<Player>(new Rogue(playerName)));
            continue;
        }
    }
}

bool Mtmchkin::isGameOver() const {
    for (const std::unique_ptr<Player> &i: this->m_PlayersDeque) {
        if (!i->isKnockedOut() && !i->isWin()) {
            return false;
        }
    }
    return true;
}

void Mtmchkin::playRound() {
    m_rounds++;
    printRoundStartMessage(m_rounds);
    int size = (int) this->m_PlayersDeque.size();
    for (int i = 0; i < size; ++i) {

        printTurnStartMessage(m_PlayersDeque.front()->getName());
        m_cardDeck.front()->applyEncounter(*this->m_PlayersDeque.front());
        if (this->m_PlayersDeque.front()->isKnockedOut()) {
            this->m_Loosers.push_front(move(this->m_PlayersDeque.front()));
            this->m_PlayersDeque.pop_front();
            m_cardDeck.push_back(move(this->m_cardDeck.front()));
            m_cardDeck.pop_front();
            if (isGameOver()) {
                printGameEndMessage();
                i = size;
            }
            continue;
        }
        if (this->m_PlayersDeque.front()->isWin()) {
            this->m_Winners.push_back(move(this->m_PlayersDeque.front()));
            this->m_PlayersDeque.pop_front();
            m_cardDeck.push_back(move(this->m_cardDeck.front()));
            m_cardDeck.pop_front();
            if (isGameOver()) {
                printGameEndMessage();
                i = size;
            }
            continue;
        }

        m_cardDeck.push_back(move(this->m_cardDeck.front()));
        m_cardDeck.pop_front();
        m_PlayersDeque.push_back(move(this->m_PlayersDeque.front()));
        m_PlayersDeque.pop_front();
    }
}

void Mtmchkin::printLeaderBoard() const {

    printLeaderBoardStartMessage();
    int rank = 1;
    for (const std::unique_ptr<Player> &m_Winner: this->m_Winners) {
        printPlayerLeaderBoard(rank, *m_Winner);
        rank++;
    }

    for (const std::unique_ptr<Player> &k: this->m_PlayersDeque) {
        printPlayerLeaderBoard(rank, *k);
        rank++;
    }
    for (const std::unique_ptr<Player> &m_Looser: this->m_Loosers) {
        printPlayerLeaderBoard(rank, *m_Looser);
        rank++;
    }
}

bool isPlayerNameCorrect(string &playerName) {
    if (!isInEnglish(playerName) || playerName.length() > 15) {
        return false;
    }
    return true;
}

string &isPlayerClassCorrect(string &playerType) {
    if (playerType == "Rogue" || playerType == "Wizard" || playerType == "Fighter") {
        return playerType;
    }
    playerType = "invalidClass";
    return playerType;
}

int Mtmchkin::getNumberOfRounds() const {
    return this->m_rounds;
}
