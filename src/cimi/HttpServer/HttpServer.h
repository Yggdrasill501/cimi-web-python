#ifndef HTTPSERVER_H
#define HTTPSERVER_H

#include <netinet/in.h>
#include "string"

class HttpServer {
public:
    explicit HttpServer(int port);

    void start();

    bool shouldShutdown(const std::string& request);
    std::string getHtmlContent(const std::string& filepath);

    int acceptNewConnection();
    std::string readRequest(int client_fd);
    void sendResponse(int client_fd, const std::string& httpResponse);
    bool isShutdownCommand(const std::string& request);

private:
    int server_fd;
    int port;

    struct sockaddr_in address{};

};

#endif // HTTPSERVER_H

