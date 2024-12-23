#ifndef GET_H
#define GET_H

#include "request.h"

class Get : public Request {
public:
    explicit Get(const std::string &url);
};

#endif //GET_H
