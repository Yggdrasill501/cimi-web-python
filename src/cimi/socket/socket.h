//
// Created by Filip Žitný on 02/02/2024.
//
#ifndef CIMISERVER_SOCKET_H
#define CIMISERVER_SOCKET_H
# include <netinet/in.h>

class Socket {
private:
    int sockfd;
    struct sockaddr_in address;

public:
    Socket() ;
    ~Socket();

    bool create();
    bool bindSocket();
    bool listenSocket();
    int acceptConnection();
};
#endif // CIMISERVER_SOCKET_H