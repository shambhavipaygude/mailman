#include "get.h"
#include <iostream>
#include <curl/curl.h>

get::get(const std::string &url) {
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "GET request failed: " << curl_easy_strerror(res) << std::endl;
            successFlag = false;
        } else {
            std::cout << "GET request succeeded!" << std::endl;
            successFlag = true;
        }

        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
}

bool get::isSuccessful() {
    return successFlag;
}

/*
  ∧,,,∧
(  ̳• · • ̳)
/     づ♡
*/
