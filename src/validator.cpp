#include "../include/validator.h"
#include <regex>
#include <algorithm>
#include <iostream>

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

bool validateHeader(const std::string& header) {
    // Find the position of the colon
    size_t pos = header.find(":");

    if (pos == std::string::npos) {
        std::cerr << "Invalid header format: Missing colon in header: " << header << std::endl;
        return false;
    }

    // Check if there is any space before the colon
    if (pos > 0 && std::isspace(header[pos - 1])) {
        std::cerr << "Invalid header format: Extra space before colon in header: " << header << std::endl;
        return false;
    }

    // Check if there is any space after the colon
    if (pos + 1 < header.size() && std::isspace(header[pos + 1])) {
        std::cerr << "Invalid header format: Extra space after colon in header: " << header << std::endl;
        return false;
    }

    // Ensure that there is at least one space after the colon (value must exist)
    if (pos + 1 == header.size()) {
        std::cerr << "Invalid header format: Missing value after colon in header: " << header << std::endl;
        return false;
    }

    return true;
}

bool validateKey(const std::string& key) {
    // Key should not be empty and must not contain spaces
    if (key.empty()) {
        return false;
    }

    if (key.find(" ") != std::string::npos) {
        return false;
    }

    return true;
}

// Function to validate the value (after the colon)
bool validateValue(const std::string& value) {
    // Value should not be empty
    if (value.empty()) {
        std::cerr << "Invalid value: Value is empty." << std::endl;
        return false;
    }

    return true;
}

