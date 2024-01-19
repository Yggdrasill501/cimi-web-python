#ifndef HTTPSERVER_H
#define HTTPSERVER_H

#include "http_request.h"
#include "http_response.h"

class HttpServer {
private:
    int port;
    // Additional properties for socket, etc.

public:
    HttpServer(int port);

    void start();

private:
    void handleConnection(/* connection */);

    HttpRequest parseRequest(/* from connection */);

    HttpResponse handleRequest(const HttpRequest& request);

    void sendResponse(/* to connection */, const HttpResponse& response);
};

#endif // HTTPSERVER_H

