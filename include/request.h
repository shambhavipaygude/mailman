#ifndef REQUEST_H
#define REQUEST_H

#include <map>
#include <string>
#include <curl/curl.h>

class Request {
protected:
    CURL *curl;
    std::string url;
    std::string method;
    struct curl_slist *list = NULL;
    std::string response_data;
    std::string response_headers;
    curl_off_t response_size;
    long response_code;

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



public:
    explicit Request(const std::string &url, const std::string &method = "GET");
    virtual ~Request();

    void addHeader(const std::string &headerName, const std::string &headerValue);
    void setHeaders();
    virtual void send();

    std::string getResponseData() const;
    std::string getResponseHeaders() const;
    curl_off_t getResponseSize() const;
    long getResponseCode() const;
    std::map<std::string, std::string> headers;
};

#endif // REQUEST_H
