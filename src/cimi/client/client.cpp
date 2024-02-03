//
// Created by Filip Žitný on 03/02/2024.
//
#include "client.h"
#include <socket/socket.h>
#include <cstring>
#include <iostream>

Client::Client() : socket(Socket()) {}

bool Client::connectToServer(int port, const std::string& serverAddress) {
    return socket.connectToServer(serverAddress, port);
}

void Client::sendMessage(const std::string& message) {
    const char *msg = message.c_str();
    if (send(socket.getSockfd(), msg, strlen(msg) + 1, 0) < 0) {
        std::cerr << "Failed to send message" << std::endl;
    }
}

void Client::parseAddress(const std::string &address) {

}