#ifndef POST_H
#define POST_H
#include <request.h>
#include <string>

class post : public request {
private:
    std::string response;
    bool successFlag;

public:
    post(const std::string &url, const std::string &data);
    bool isSuccessful();
};

#endif //POST_H

/*
  ∧,,,∧
(  ̳• · • ̳)
/     づ♡
*/