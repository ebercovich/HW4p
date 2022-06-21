//
// Created by eyalb on 10/06/2022.
//

#ifndef HW4_EXCEPTION_H
#define HW4_EXCEPTION_H

#include <string>
#include <exception>

using namespace std;

class NonPositive : public exception {

public:
    explicit NonPositive(bool);

    NonPositive(const NonPositive &) noexcept = default;

    ~NonPositive() override = default;

    const char *what() const noexcept override;

private:
    bool m_natural;
};

class InputStringException : public exception {
public:
    InputStringException() = default;

    InputStringException(const InputStringException &) noexcept = default;

    ~InputStringException() noexcept override = default;

    const char *what() const noexcept override;
};

class DeckFileNotFound : public exception {
public:
    DeckFileNotFound() = default;

    DeckFileNotFound(const DeckFileNotFound &) noexcept = default;

    ~DeckFileNotFound() override = default;

    const char *what() const noexcept override;
};

class DeckFileFormatError : public exception {
public:
    explicit DeckFileFormatError(int) noexcept;

    DeckFileFormatError(const DeckFileFormatError &)  = default;

    ~DeckFileFormatError() noexcept override = default;

    const char *what() const noexcept override;

private:
    std::string m_massage;
};

class DeckFileInvalidSize : public exception {
public:
    DeckFileInvalidSize() = default;

    DeckFileInvalidSize(const DeckFileInvalidSize &) noexcept = default;

    ~DeckFileInvalidSize() noexcept override = default;

    const char *what() const noexcept override;
};

#endif //HW4_EXCEPTION_H