#include "../include/validator.h"
#include <regex>
#include <algorithm>

const std::array<std::string, 4> validMethods = {"GET", "POST", "PUT", "DELETE"};

bool validateMethod(const std::string& method) {
    return std::ranges::find(validMethods, method) != validMethods.end();
}

bool validateURL(const std::string& url) {
    if (url.empty()) {
        return false;
    }

    const std::regex urlRegex(
    R"(^((https?|ftp):\/\/)?((([a-zA-Z0-9\-_]+\.)+[a-zA-Z]{2,}|localhost|(\d{1,3}\.){3}\d{1,3}))(:[0-9]{1,5})?(\/[^\s]*)?$)"
    );

    return std::regex_match(url, urlRegex);
}
