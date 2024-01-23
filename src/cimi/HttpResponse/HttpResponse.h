#ifndef HTTPRESPONSE_H
#define HTTPRESPONSE_H

#include <string>
#include <map>

class HttpResponse {
public:
    int status_code;
    std::map<std::string, std::string> headers;
    std::string body;

    HttpResponse(int code);

    // Method to generate a formatted HTTP response...
};

#endif // HTTPRESPONSE_H

