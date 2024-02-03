//
// Created by Filip Žitný on 02/02/2024.
//
#ifndef CIMISERVER_SOCKET_H
#define CIMISERVER_SOCKET_H
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
    bool bindSocket(int port);
    bool listenSocket();
    int acceptConnection();
    bool connectToServer(const std::string& serverAddress, int port);
    static bool parseAddress(const std::string& addrStr, struct in_addr& addr);
};

#endif // CIMISERVER_SOCKET_H