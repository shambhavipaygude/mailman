#include "post.h"
#include <iostream>
#include <curl/curl.h>

post::post(const std::string &url, const std::string &data) {
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_POST, 1L);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());

        // Perform the request
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "POST request failed: " << curl_easy_strerror(res) << std::endl;
            successFlag = false;
        } else {
            std::cout << "POST request succeeded!" << std::endl;
            successFlag = true;
        }

        // Clean up
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
}

bool post::isSuccessful() {
    return successFlag;
}

/*
  ∧,,,∧
(  ̳• · • ̳)
/     づ♡
*/