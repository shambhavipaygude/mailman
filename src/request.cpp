#include "request.h"

#include <iostream>
#include <ostream>
#include <stdexcept>

Request::Request(const std::string &url, const std::string &method) : url(url), method(method), curl(curl_easy_init()) {
    curl = curl_easy_init();
    if (!curl) {
        throw std::runtime_error("Failed to initialize curl");
    }
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
}

Request::~Request() {
    if (list) {
        curl_slist_free_all(list);
    }
    curl_easy_cleanup(curl);
}

void Request::addHeader(const std::string &headerName, const std::string &headerValue) {
    headers[headerName] = headerValue;
}

void Request::setHeaders() {
    for (const auto &header : headers) {
        std::string headerString = header.first + ": " + header.second;
        std::cout<<"Appending header: "<<headerString<<std::endl;
        list = curl_slist_append(list, headerString.c_str());
    }
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);
}

void Request::performRequest() {
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_data);
    curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, header_callback);
    curl_easy_setopt(curl, CURLOPT_HEADERDATA, &response_headers);

    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        throw std::runtime_error("curl_easy_perform() failed: " + std::string(curl_easy_strerror(res)));
    }

    curl_easy_getinfo(curl, CURLINFO_CONTENT_LENGTH_DOWNLOAD_T, &response_size);
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);

}

void Request::send() {
    performRequest();
}

std::string Request::getResponseData() const {
    return response_data;
}

std::string Request::getResponseHeaders() const {
    return response_headers;
}

curl_off_t Request::getResponseSize() const {
    return response_size;
}

long Request::getResponseCode() const {
    return response_code;
}


