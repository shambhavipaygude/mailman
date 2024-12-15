//
// Created by a7x on 12/15/24.
//

#ifndef REQUEST_H
#define REQUEST_H
#include <array>
#include <string>
#include "curl/curl.h"


class request {
public:
    request();
    bool setUrl(std::string &url);
    bool setMethod(std::string &method);
    bool setupRequest();
    bool performRequest();

private:
    CURL *curl;
    std::string method;
    std::string url;
    std::array<std::string,4> validMethods = {"GET", "POST", "PUT", "DELETE"};
    CURLcode res;
};

#endif //REQUEST_H
