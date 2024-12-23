#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <string>
#include <array>

extern const std::array<std::string, 4> validMethods;

bool validateMethod(const std::string& method);
bool validateURL(const std::string& url);
bool validateHeader(const std::string& header);
bool validateKey(const std::string& key);
bool validateValue(const std::string& value);

#endif 
