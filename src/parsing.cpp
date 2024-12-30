#include "parsing.h"
#include "get.h"
#include "validator.h"
#include <sstream>
#include <iostream>
#include <memory>

bool Parsing::parseInput(std::string &input) {
    std::istringstream iss(input);
    std::string token, url, method = "GET";

    iss >> token;
    if (token != "mailman") {
        std::cerr << "Error: Input must start with 'mailman'" << std::endl;
        return false;
    }

    while (iss >> token) {
        if (token == "-u") {
            if (!(iss >> url) || !validateURL(url)) {
                std::cerr << "Error: Invalid URL." << std::endl;
                return false;
            }
        } else if (token == "-m") {
            if (!(iss >> method) || !validateMethod(method)) {
                std::cerr << "Error: Invalid method." << std::endl;
                return false;
            }
        } else if (token == "-h") {
            std::string header;
            while (iss >> std::ws && std::getline(iss, header, ' ')) {
                if (!validateHeader(header)) {
                    std::cerr << "Error: Invalid header format." << std::endl;
                    return false;
                }

                size_t pos = header.find(':');
                std::string key = header.substr(0, pos);
                std::string value = header.substr(pos + 1);
                std::cout<<"key"<<key<<std::endl;
                std::cout<<"value"<<value<<std::endl;
                if (!validateKey(key) || !validateValue(value)) {
                    std::cerr << "Error: Invalid header key-value pair." << std::endl;
                    return false;
                }
                headers[key] = value;
            }
        }
    }

    try {
        std::cout<<url<<' '<<method<<std::endl;
        auto request = createRequest(url, method);
        for (const auto &header : headers) {
            request->addHeader(header.first, header.second);
        }
        std::cout<<"Appended headers"<<std::endl;
        request->setHeaders();
        std::cout<<"Set headers"<<std::endl;
        request->send();
        std::cout<<"Sent request"<<std::endl;

        std::cout << "Response Data: " << request->getResponseData() << std::endl;
        std::cout << "Response Headers: " << request->getResponseHeaders() << std::endl;
        return true;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return false;
    }
}

std::unique_ptr<Request> Parsing::createRequest(const std::string &url, const std::string &method) {
    if (method == "GET") {
        return std::make_unique<Get>(url);
    } else {
        // Unsupported method
        throw std::invalid_argument("Error: Unsupported HTTP method: " + method);
    }
}

