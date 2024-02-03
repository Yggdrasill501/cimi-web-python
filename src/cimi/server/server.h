//
// Created by Filip Žitný on 03/02/2024.
//
#ifndef CIMIWEB_SERVER_H
#define CIMIWEB_SERVER_H
#include <socket/socket.h>

class Server{
private:
    Socket serverSocket;
    int port = 8080;

public:
  Server();
  void runServer();
};

#endif //CIMIWEB_SERVER_H