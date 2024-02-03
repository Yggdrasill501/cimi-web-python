//
// Created by Filip Žitný on 03/02/2024.
//
#ifndef CIMISERVER_SERVER_H
#define CIMISERVER_SERVER_H
#include <socket/socket.h>

class Server{
private:
    Socket serverSocket;
    int port = 8080;

public:
  Server();
  void runServer();
};

#endif //CIMISERVER_SERVER_H