//
// Created by Filip Žitný on 02/02/2024.
//
#include <iostream>
#include <cimi/socket/socket.h>
#include <string>
#include <fstream>
#include <sstream>
#include <unistd.h>

std::string readHTMLFile(const std::string& filepath) {
    std::ifstream fileStream(filepath);
    std::stringstream buffer;
    buffer << fileStream.rdbuf();
    return buffer.str();
}

int main() {
    Socket serverSocket;

    // Create, bind, and listen on the socket
    if (!serverSocket.create()) {
        perror("Socket creation failed");
        return -1;
    }
    if (!serverSocket.bindSocket()) {
        perror("Socket bind failed");
        return -1;
    }
    if (!serverSocket.listenSocket()) {
        perror("Socket listen failed");
        return -1;
    }

    std::cout << "Server is listening on port 8080..." << std::endl;

    while (true) {

        // Accept a new connection
        int newSocket = serverSocket.acceptConnection();
        if (newSocket < 0) {
            perror("Accept failed");
            continue; // Skip to the next iteration
        }

        char buffer[30000] = {0};
        long valread = read(newSocket, buffer, 30000); // Read request
        std::cout << "----- Request -----\n" << buffer << std::endl;

        // Very basic request handling
        if (strncmp(buffer, "GET", 3) == 0) {
            std::string htmlContent = readHTMLFile("index.html"); // Ensure you have an index.html file
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

        close(newSocket); // Close the socket to this client
    }
    return 0;
}