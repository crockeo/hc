#ifndef _HC_EXCEPTION_HPP_
#define _HC_EXCEPTION_HPP_

//////////////
// Includes //
#include <exception>
#include <string>

//////////
// Code //

// To distinguish between different HCExceptions.
enum HCType {
    HC_WINDOW_EXCEPTION
};

// A custom exception for this project.
class HCException : public std::exception {
private:
    std::string msg;
    HCType type;

public:
    // Creating an HCException with a message and a type.
    HCException(std::string, HCType);
    
    // The message of this HCException.
    const char* what() throw();
};

#endif
