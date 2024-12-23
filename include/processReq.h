#ifndef PROCESSREQ_H
#define PROCESSREQ_H

#include <string>
#include <map>
#include <vector>
#include <array>
#include "curl/curl.h"

class processReq {
private:
    CURL *curl;
    CURLcode res;
    std::string method;
    std::string url;
    std::array<std::string,4> validMethods = {"GET", "POST", "PUT", "DELETE"};
    std::map<std::string, std::string> headers;
    std::string auth;
    std::string input;
    std::string header;

public:

    processReq();
    bool setUrl(std::string &url);
    bool setMethod(std::string &method);
    bool setHeaders(std::string &key, std::string &value);
    bool setAuthorization(std::string &auth);
    bool processHeader(const std::string& header);
    bool processRequest();
};

#endif 

/*
  ∧,,,∧
(  ̳• · • ̳)
/     づ♡
*/