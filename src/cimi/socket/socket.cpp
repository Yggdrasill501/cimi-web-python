//
// Created by Filip Žitný on 02/02/2024.
//
#include <cimi/socket/socket.h>
#include <cstring>
#include <unistd.h>

Socket::Socket(): sockfd(-1) {
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);
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

bool Socket::bindSocket(){
    return bind(sockfd, (struct sockaddr*)&address, sizeof(address)) >= 0;
}

bool Socket::listenSocket(){
    return listen(sockfd, 10) >= 0;
}

int Socket::acceptConnection(){
    int addrlen = sizeof(address);
    return accept(sockfd, (struct sockaddr*)&address, (socklen_t*)&addrlen);
}