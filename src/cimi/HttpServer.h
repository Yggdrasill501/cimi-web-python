#ifndef HTTPSERVER_H
#define HTTPSERVER_H

#include "http_request.h"
#include "http_response.h"
#include "WebSocket"

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
    
    bool isWebSocketRequest(const HttpRequest& request);
    void handleWebSocket(/* connection */, const HttpRequest& request);}

#endif // HTTPSERVER_H
