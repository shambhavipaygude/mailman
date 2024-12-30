#ifndef PARSING_H
#define PARSING_H

#include "request.h"
#include <string>
#include <map>
#include <memory>

class Parsing {
public:
    bool parseInput(std::string &input);
private:
    std::unique_ptr<Request> createRequest(const std::string &url, const std::string &method);
    std::map<std::string, std::string> headers;
};

bool validateURL(const std::string &url);
bool validateMethod(const std::string &method);
bool validateHeader(const std::string &header);

#endif // PARSING_H
