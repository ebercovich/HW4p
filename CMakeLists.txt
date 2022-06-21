cmake_minimum_required(VERSION 3.21)
project(HW4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(HW4
        Mtmchkin.h
        Mtmchkin.cpp
        Players/Player.h
        Exception.h
        Cards/Barfight.cpp
        CardS/Barfight.h
        Cards/Merchant.cpp
        Cards/Merchant.h
        Cards/Pitfall.cpp
        Cards/Pitfall.h
        Cards/Treasure.cpp
        Cards/Treasure.h
        Cards/Battle.h
        Cards/Fairy.cpp
        Cards/Fairy.h
        Cards/Card.h
        Cards/Dragon.h
        Cards/Goblin.h
        Cards/Vampire.h
        Players/Player.cpp
        Players/Rogue.h
        Players/Rogue.cpp
        Players/Fighter.h
        Players/Fighter.cpp
        Players/Wizard.h
        Players/Wizard.cpp
        Cards/Battle.cpp
        Cards/Card.cpp
        Cards/Dragon.cpp
        Cards/Goblin.cpp
        Cards/Vampire.cpp
        Exception.cpp
        test.cpp
        utilities.h
        utilities.cpp Cards/Gang.cpp Cards/Gang.h)