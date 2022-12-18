//
// Created by danit on 13.12.2022.
//

#ifndef OOP_EXCEPTIONS_H
#define OOP_EXCEPTIONS_H

#include <stdexcept>

class gameError : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

class mapSketchError : public gameError {
public:
    using gameError::gameError;

    mapSketchError() : gameError("The map sketch does not have the correct size") {};
};

class mapConversionError : public gameError {
public:
    using gameError::gameError;

    mapConversionError() : gameError("Wrong conversion from sf::Image to std::vector<std::vector<Cell>>") {};
};

#endif //OOP_EXCEPTIONS_H
