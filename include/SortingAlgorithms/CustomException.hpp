#ifndef __CUSTOMEXCEPTION_HPP__
#define __CUSTOMEXCEPTION_HPP__

#include <exception>

class TimeoutException : public std::exception {
    const char *what() const throw () {
        return ("TimeoutException: The algorithm took too long to execute.");
    }
};

#endif // __CUSTOMEXCEPTION_HPP__