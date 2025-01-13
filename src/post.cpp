//
// Created by a7x on 12/23/24.
//

#include "../include/post.h"


Post::Post(const std::string &url,std::string data) : Request(url, "POST") {}

void Post::send() {
    // data example :
    // key1=value1&key2=value2" KEY VALUE PAIR
    // R"({"key1": "value1", "key2": "value2"})" JSON
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, data.size());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
    performRequest();
}