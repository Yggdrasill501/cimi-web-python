#include "cimi/HttpServer/HttpServer.h"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fstream>
#include <sstream>
#include <string>

HttpServer::HttpServer(int port) : port(port) {
    // I AM SOCKET
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // I AM SERVER ADDRESS
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);


    // I BIND SOCKET TO ADDRESS
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
    

    // I LISTEN TO INCOMING CONNECTIONS
    if (listen(server_fd, 10) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

}

void HttpServer::start() {
    while (true) {
        std::string htmlContent = getHtmlContent("index.html");
        std::string httpResponse = "HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: " + std::to_string(htmlContent.length()) + "\n\n" + htmlContent;

        std::cout << "\n+++++++ Waiting for new connection ++++++++\n\n";

        struct sockaddr_in client_addr{};
        socklen_t client_len = sizeof(client_addr);
        int client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len);

        if (client_fd < 0) {
            perror("In accept");
            continue;
        }

        char buffer[1024] = {0};  // Declare buffer here
        read(client_fd, buffer, 1024);

        std::string request(buffer);
        if (shouldShutdown(request)) {
            std::string response = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 7\n\nGoodbye";
            write(client_fd, response.c_str(), response.length());
            close(client_fd);
            break; // Break out of the loop to stop the server
        }

        write(client_fd, httpResponse.c_str(), httpResponse.length());

        close(client_fd);
    }
}

bool HttpServer::shouldShutdown(const std::string& request) {
    return request.find("GET /shutdown HTTP/1.1") != std::string::npos;
}

std::string HttpServer::getHtmlContent(const std::string& filepath) {
    std::ifstream file(filepath);
    if (!file.is_open()) {
        return "HTTP/1.1 404 Not Found\nContent-Type: text/plain\nContent-Length: 13\n\n404 Not Found";
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}