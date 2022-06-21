//
// Created by eyalb on 10/06/2022.
//
#include <string>
#include "Exception.h"

//NonPositive
NonPositive::NonPositive(bool isNatural) : m_natural(isNatural) {}

const char *NonPositive::what() const noexcept {
    if (this->m_natural) {
        return "Input is out of range, try a m_natural number.";
    } else
        return "Input is out of range, try a non-negative number.";
}

//NonPositive finished
//InputStringException
const char *InputStringException::what() const noexcept {
    return "A problematic string entered, "
           "make sure the string is in english letters, "
           "no spaces and no longer than 15 characters.";
}

//InputStringException finished
//DeckFileNotFound
const char *DeckFileNotFound::what() const noexcept {
    return "Deck File Error: File not found";
}

//DeckFileNotFound finished
//DeckFileFormatError
DeckFileFormatError::DeckFileFormatError(int line) noexcept {
    this->m_massage = "Deck File Error: File format error in line " + to_string(line);
}

const char *DeckFileFormatError::what() const noexcept {
    return this->m_massage.c_str();
}

//DeckFileFormatError finished
//DeckFileInvalidSize
const char *DeckFileInvalidSize::what() const noexcept {
    return "Deck File Error: Deck size is invalid";
}
//DeckFileInvalidSize finished