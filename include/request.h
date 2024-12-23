#ifndef REQUEST_H
#define REQUEST_H

#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <iostream>
#include <array>
#include "processReq.h"  

class request {
public:
    std::string url;                          
    std::string method;                       
    std::map<std::string, std::string> headers; 
    std::string auth;        
    
    processReq reqProcessor;                
    bool parseInput(std::string &input);                 

};

#endif 

/*
  ∧,,,∧
(  ̳• · • ̳)
/     づ♡
*/
