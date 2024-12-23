//
// Created by a7x on 12/20/24.
//

#ifndef GET_H
#define GET_H
#include <request.h>


class get : public request {
private:
    std::string response;
    bool successFlag;

public:
    get(const std::string &url);
    bool isSuccessful(); 
};



#endif //GET_H