//
// Created by a7x on 12/20/24.
//
#include "get.h"

get::get(const std::string &url) : request(url) {
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
}

