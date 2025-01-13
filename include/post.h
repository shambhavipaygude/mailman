//
// Created by a7x on 12/23/24.
//

#ifndef POST_H
#define POST_H
#include <request.h>

class Post: public Request {
private:
    std::string data;

public:
    explicit Post(const std::string &url, std::string data);
    void send() override;
};

#endif //POST_H
