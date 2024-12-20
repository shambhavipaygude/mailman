#include <iostream>

#include "get.h"
#include "curl/curl.h"
#include "../include/request.h"

int main() {
    // initialize curl
    curl_global_init(CURL_GLOBAL_ALL);
    std::string url = "https://api.coindesk.com/v1/bpi/currentprice.json";
    get x(url);
    x.send();
    std::cout<<x.getResponseData();

    //something is wrong with get response headers


    // release curl resources
    curl_global_cleanup();
    return 0;
}
