
#ifndef REQUEST_H
#define REQUEST_H

#include <map>
#include <string>
#include "curl/curl.h"

class request {
protected:
    CURL *curl;
    std::string url;
    std::map <std::string,std::string> headers;

    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
        ((std::string*)userp)->append((char*)contents, size * nmemb);
        return size * nmemb;
    }

    static size_t header_callback(char *buffer, size_t size, size_t nitems, void *userdata) {
        size_t total_size = size * nitems;
        std::string *headers = static_cast<std::string *>(userdata);

        headers->append(buffer, total_size);

        return total_size;
    }

    std::string response_data;
    std::string response_headers;

    curl_off_t size;

public:
    explicit request(const std::string &url);
    ~request();

    void addHeader(std::string headerName, std::string headerValue);
    void setHeaders();

    void send();

    std::string getResponseData() const ;
    std::string getResponseHeaders()const ;
};

#endif //REQUEST_H
