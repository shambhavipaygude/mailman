//
// Created by a7x on 12/15/24.
//

#include "request.h"
#include <iostream>
#include "curl/curl.h"
#include <string>
#include "validator.h"

request::request() {
    curl = curl_easy_init();
    if (!curl) {
        std::cerr << "Error initializing curl" << std::endl;
    }
}

bool request::setUrl(std::string &_url) {
    if (!validateURL(_url)) {
        std::cerr << "Invalid URL" << std::endl;
        return false;
    }
    this->url = _url;
    return true;
}

bool request::setMethod(std::string &_method) {
    if (!validateMethod(_method)) {
        std::cerr << "Invalid method" << std::endl;
        return false;
    }
    this->method = _method;
    return true;
}

bool request::setupRequest() {
    std::cout << "Setting up request" << std::endl;
    if (this->method.empty() || this->url.empty()) {
        std::cerr << "Method or URL not set" << std::endl;
        return false;
    }

    curl_easy_setopt(curl, CURLOPT_URL, this->url.c_str()); // c.str to convert string to c style array for curl
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, this->method.c_str());

    return true;
}

bool request::performRequest() {
    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        std::cerr << "Error performing request: " << curl_easy_strerror(res) << std::endl;
        return false;
    }
    return true;
}


