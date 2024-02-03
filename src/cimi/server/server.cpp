//
// Created by Filip Žitný on 03/02/2024.
//
#include <socket/socket.h>
#include <server/server.h>
#include <handler/html_handler.h>
#include <iostream>
#include <cstring>
#include <unistd.h>

Server::Server() {
    serverSocket = Socket();

    if (!serverSocket.create()) {
        throw std::runtime_error("Socket creation failed");
    }

    if (!serverSocket.bindSocket()) {
        throw std::runtime_error("Socket bind failed");
    }

    if (!serverSocket.listenSocket()) {
        throw std::runtime_error("Socket listen failed");
    }
}

void Server::runServer() {
    std::cout << "server is listening on port " << port << "..." << std::endl;

    while (true) {
        int newSocket = serverSocket.acceptConnection();
        if (newSocket < 0) {
            std::cerr << "Accept failed" << std::endl;
            continue;
        }

        char buffer[30000] = {0};
        read(newSocket, buffer, 30000);
        std::cout << "----- Request -----\n" << buffer << std::endl;

        if (strncmp(buffer, "GET", 3) == 0) {
            std::string htmlContent = HtmlLHandler::readHtmlFile("index.html");
            if (htmlContent.empty()) {
                std::string notFoundMessage = "HTTP/1.1 404 Not Found\nContent-Length: 0\n\n";
                write(newSocket, notFoundMessage.c_str(), notFoundMessage.length());
            } else {
                std::string httpResponse = "HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: " + std::to_string(htmlContent.length()) + "\n\n" + htmlContent;
                write(newSocket, httpResponse.c_str(), httpResponse.length());
            }
        } else {
            std::string message = "HTTP/1.1 400 Bad Request\nContent-Length: 0\n\n";
            write(newSocket, message.c_str(), message.length());
        }

        close(newSocket);
    }
}