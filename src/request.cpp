#include "request.h"
#include <iostream>
#include "curl/curl.h"
#include "validator.h"
#include "get.h"
#include "post.h"
#include "processReq.h"

bool request::parseInput(std::string &input) {
    std::istringstream iss(input);
    std::string token;

    iss >> token;
    if (token != "mailman") {
        std::cerr << "Error: Input must start with 'mailman'" << std::endl;
        return false;
    }

    while (iss >> token) {
        if (token == "-u") {
            std::string url;
            if (iss >> url) {
                if (!reqProcessor.setUrl(url)) return false;
            } else {
                std::cerr << "No URL provided after -u" << std::endl;
                return false;
            }
        } else if (token == "-m") {
            std::string method;
            if (iss >> method) {
                if (!reqProcessor.setMethod(method)) return false;
            } else {
                std::cerr << "No method provided after -m" << std::endl;
                return false;
            }
        } else if (token == "-a") {
            if (iss >> auth) {
                std::cout << "Authorization set to: " << auth << std::endl;
            } else {
                std::cerr << "No authorization type provided after -a" << std::endl;
                return false;
            }
        } else if (token == "-h") {
            std::vector<std::string> headers;  
            std::string header;

            while (iss >> std::ws) {
                if (iss >> header) {
                    if (header.find("-h") != std::string::npos) {
                        continue;
                    }
                    validateHeader(header);
                    headers.push_back(header);
                }
            }

            for (int i = 0; i < headers.size(); i++) {
                std::cout << headers[i] + " \n";
                reqProcessor.processHeader(headers[i]);
            }
            std::cout << '\n';
        }
    }

    // Set default authorization if not provided
    if (auth.empty()) {
        auth = "Bearer token"; 
        std::cout << "Default authorization set" << std::endl;
    }

    return reqProcessor.processRequest();
}

/*
  ∧,,,∧
(  ̳• · • ̳)
/     づ♡
*/
