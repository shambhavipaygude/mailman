#include <iostream>
#include <vector>
#include <algorithm>
#include <curl/curl.h>
#include "processReq.h"
#include "get.h"
#include "validator.h"

processReq::processReq() {
    curl = curl_easy_init();
    if (!curl) {
        std::cerr << "Error initializing curl" << std::endl;
    }
}

bool processReq::setUrl(std::string &_url) {
    if (!validateURL(_url)) {
        std::cerr << "Invalid URL" << std::endl;
        return false;
    }
    this->url = _url;
    return true;
}

bool processReq::setMethod(std::string &_method) {
    if (!validateMethod(_method)) {
        std::cerr << "Invalid method" << std::endl;
        return false;
    }
    this->method = _method;
    return true;
}

bool processReq::processHeader(const std::string& header) {
    size_t pos = header.find(":");

    if (pos == std::string::npos) {
        std::cerr << "Invalid header format: Missing colon in header: " << header << std::endl;
        return false;
    }

    std::string key = header.substr(0, pos);
    std::string value = header.substr(pos + 1);

    key.erase(0, key.find_first_not_of(" \t\n\r\f\v"));
    key.erase(key.find_last_not_of(" \t\n\r\f\v") + 1);

    value.erase(0, value.find_first_not_of(" \t\n\r\f\v"));
    value.erase(value.find_last_not_of(" \t\n\r\f\v") + 1);

    if (!validateKey(key)) {
        return false;
    }

    if (!validateValue(value)) {
        return false;
    }
    std::cout << "Header is valid: Key = '" << key << "', Value = '" << value << "'" << std::endl;
    setHeaders(key, value);
    return true;
}

bool processReq::processRequest() {
    if (this->url.empty() || this->method.empty()) {
        std::cerr << "Error: URL or method is not set." << std::endl;
        return false;
    }

    std::cout << "Processing request..." << std::endl;
    std::cout << "URL: " << this->url << std::endl;
    std::cout << "Method: " << this->method << std::endl;

    request req(this->url);
    for (const auto& header : this->headers) {
        req.addHeader(header.first, header.second);
    }
    req.setHeaders();

    if (this->method == "GET") {
        req.send();
    } else if (this->method == "POST") {
        req.send();
    }

    std::cout << "Response Data: " << req.getResponseData() << std::endl;
    std::cout << "Response Headers: " << req.getResponseHeaders() << std::endl;

    return true;
}