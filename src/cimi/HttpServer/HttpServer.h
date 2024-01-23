#ifndef HTTPSERVER_H
#define HTTPSERVER_H

#include <netinet/in.h>
#include "string"

class HttpServer {
public:
    explicit HttpServer(int port);

    void start() const;

    static bool shouldShutdown(const std::string& request);

private:
    int server_fd;
    int port;

    struct sockaddr_in address{};

};

#endif // HTTPSERVER_H

