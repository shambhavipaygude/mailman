#include <iostream>
#include "curl/curl.h"
#include "request.h"

int main() {
    // initialize curl
    curl_global_init(CURL_GLOBAL_ALL);
    request r = request();
    std::string url = "http://127.0.0.1:8080";
    std::string method = "GET";
    r.setUrl(url);
    r.setMethod(method);
    r.setupRequest();
    r.performRequest();

    // release curl resources
    curl_global_cleanup();
    return 0;
}
