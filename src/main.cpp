#include <iostream>
#include "request.h"

int main() {
    curl_global_init(CURL_GLOBAL_ALL);

    std::string input;
    std::cout << "Enter input in the format: -u URL -m METHOD -a AUTH -h HEADERS" << std::endl;
    std::getline(std::cin, input);

    request r;
    if (!r.parseInput(input)) {
        std::cerr << "Error parsing input. Please check your arguments." << std::endl;
        return 1;
    }

    curl_global_cleanup();
    return 0;
}

