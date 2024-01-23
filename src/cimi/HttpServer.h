#ifndef HTTPSERVER_H
#define HTTPSERVER_H

#include <netinet/in.h>

class HttpServer {
public:
    HttpServer(int port);
    void start();

private:
    int server_fd;
    int port;

    struct sockaddr_in address;

};

#endif // HTTPSERVER_H

