#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <string>
#include <array>

// Declare the validMethods array
extern const std::array<std::string, 4> validMethods;

// Function declarations
bool validateMethod(const std::string& method);
bool validateURL(const std::string& url);

#endif // VALIDATOR_H
