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


private:
    int server_fd;
    int port;

    struct sockaddr_in address{};

};

#endif // HTTPSERVER_H

