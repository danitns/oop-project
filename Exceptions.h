//
// Created by danit on 13.12.2022.
//

#ifndef OOP_EXCEPTIONS_H
#define OOP_EXCEPTIONS_H

#include <stdexcept>

class gameError: public std::runtime_error {
    using std::runtime_error::runtime_error;
};

class mapSketchError: public gameError {
public:
    using gameError::gameError;
    mapSketchError(): gameError("The map sketch does not have the correct size") {};
};

#endif //OOP_EXCEPTIONS_H
