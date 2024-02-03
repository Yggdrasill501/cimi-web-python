//
// Created by Filip Žitný on 03/02/2024.
//
#ifndef CIMISERVER_CLIENT_H
#define CIMISERVER_CLIENT_H
#include <socket/socket.h>
#include <string>

class Client {
private:
    int port = 8080;

public:
    Client();
    ~Client();

    void connect(int port);
    void parseAddress();
    std::string sendMessage();

};

#endif //CIMISERVER_CLIENT_H
