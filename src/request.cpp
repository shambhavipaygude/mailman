#include "request.h"
#include <stdexcept>
#include <string>

request::request(const std::string &url): url(url) {
    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL,url.c_str());
    if (!curl) {
        throw std::runtime_error("Failed to initialize curl");
    }
}

request::~request() {
    curl_easy_cleanup(curl);
}

void request::addHeader(std::string headerName, std::string headerValue) {
    headers[headerName] = headerValue;
}

void request::setHeaders() {
    struct curl_slist *list = NULL;
    for (auto &header : headers) {
        std::string headerString = header.first + ": " + header.second;
        list = curl_slist_append(list, headerString.c_str());
    }
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);
    curl_slist_free_all(list);

}

void request::send() {
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_data);
    curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, header_callback);
    curl_easy_setopt(curl, CURLOPT_HEADERDATA, &response_headers);
    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        throw std::runtime_error("curl_easy_perform() failed: " + std::string(curl_easy_strerror(res)));
    }
    else {
        curl_easy_getinfo(curl, CURLINFO_CONTENT_LENGTH_DOWNLOAD_T, &size);
    }

}

std::string request::getResponseData() const {
    return response_data;
}

std::string request::getResponseHeaders() const {
    return response_headers;
}



