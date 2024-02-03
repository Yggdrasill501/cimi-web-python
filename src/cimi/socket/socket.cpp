//
// Created by Filip Žitný on 02/02/2024.
//
#include <cimi/socket/socket.h>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <cstring>
#include <iostream>



Socket::Socket(): sockfd(-1) {
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);
}

Socket::Socket(int socket_fd) : sockfd(socket_fd) {
    if (sockfd < 0) {
        throw std::runtime_error("Invalid socket file descriptor passed to Socket constructor");
    }
}

Socket::~Socket(){
    if(sockfd != -1){
        close(sockfd);
    }
}

bool Socket::create(){
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    return sockfd != -1;
}

bool Socket::bindSocket(int port){
    return bind(sockfd, (struct sockaddr*)&address, sizeof(address)) >= 0;
}

bool Socket::listenSocket(){
    return listen(sockfd, 10) >= 0;
}

int Socket::acceptConnection(){
    int addrlen = sizeof(address);
    return accept(sockfd, (struct sockaddr*)&address, (socklen_t*)&addrlen);
}

bool Socket::connectToServer(const std::string& serverAddress, int port) {
    if (sockfd == -1 && !create()) {
        return false;
    }

    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_port = htons(port);

    if (inet_pton(AF_INET, serverAddress.c_str(), &address.sin_addr) <= 0) {
        std::cerr << "Invalid address / Address not supported" << std::endl;
        return false;
    }

    return connect(sockfd, (struct sockaddr *)&address, sizeof(address)) >= 0;
}

int Socket::getSockfd() const {
    return sockfd;
}

bool Socket::parseAddress(const std::string& addrStr, struct in_addr& addr) {
    return inet_pton(AF_INET, addrStr.c_str(), &addr) == 1;
}