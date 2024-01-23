#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H

#include <string>
#include <map>

class HttpRequest{
public:
    std::string method;
    std::string uri;
    std::map<std::string, std::string> headers;
    std::string body;

};

#endif // HTTPREQUEST_H
