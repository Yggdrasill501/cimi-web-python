//
// Created by Filip Žitný on 03/02/2024.
//
#ifndef CIMIWEB_CLIENT_H
#define CIMIWEB_CLIENT_H
#include <socket/socket.h>
#include <string>

class Client {
private:
    Socket socket;

public:
    Client();

    bool connectToServer(int port,const std::string& serverAddress);
    void sendMessage(const std::string& message);
    void parseAddress(const std::string& address);
};

#endif //CIMIWEB_CLIENT_H