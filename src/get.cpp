#include "get.h"

Get::Get(const std::string &url) : Request(url) {
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
    }
}

