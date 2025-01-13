#include <iostream>
#include "parsing.h"

int main() {
    curl_global_init(CURL_GLOBAL_ALL);

    std::string input;
    std::cout << "Enter input in the format: mailman -u URL -m METHOD -h HEADERS" << std::endl;
    std::getline(std::cin, input);

    Parsing parser;
    bool success = parser.parseInput(input);
    curl_global_cleanup();
    return success ? 0 : 1;
}
