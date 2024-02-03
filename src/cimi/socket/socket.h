//
// Created by Filip Žitný on 02/02/2024.
//
#ifndef CIMIWEB_SOCKET_H
#define CIMIWEB_SOCKET_H
#include <netinet/in.h>
#include <string>

class Socket {
private:
    int sockfd;
    struct sockaddr_in address;

public:
    Socket();
    ~Socket();
    explicit Socket(int socket_fd);
    int getSockfd() const;

    bool create();
    bool bindSocket();
    bool listenSocket();
    int acceptConnection();
    bool connectToServer(const std::string& serverAddress, int port);
    static bool parseAddress(const std::string& addrStr, struct in_addr& addr);
};

#endif // CIMIWEB_SOCKET_H