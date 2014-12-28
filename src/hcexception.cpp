#include "hcexception.hpp"

//////////
// Code //

// Creating an HCException with a message and a type.
HCException::HCException(std::string msg, HCType type) {
    this->msg = msg;
    this->type = type;
}

// The message of this HCException.
const char* HCException::what() throw() {
    return this->msg.c_str();
}
