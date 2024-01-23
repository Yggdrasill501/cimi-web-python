#include "cimi/HttpServer/HttpServer.h"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fstream>
#include <sstream>
#include <string>

HttpServer::HttpServer(int port) : port(port) {
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 10) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
}

void HttpServer::startServer() {
    addRoute("/", [this](const std::string& req) { return "HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: 13\n\nI AM A SERVER"; });
    addRoute("/shutdown", [](const std::string& req) { return "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 7\n\nGoodbye"; });

    while (true) {
        int client_fd = acceptNewConnection();
        if (client_fd < 0) continue;

        std::string request = readRequest(client_fd);
        std::string response = handleRequest(request);

        sendResponse(client_fd, response);
        close(client_fd);

        if (response.find("Goodbye") != std::string::npos) {
            break;
        }
    }
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

int HttpServer::acceptNewConnection() {
    struct sockaddr_in client_addr{};
    socklen_t client_len = sizeof(client_addr);
    int client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len);

    if (client_fd < 0) {
        perror("In accept");
    }
    return client_fd;
}

std::string HttpServer::readRequest(int client_fd) {
    char buffer[1024] = {0};
    read(client_fd, buffer, 1024);
    return std::string(buffer);
}

void HttpServer::sendResponse(int client_fd, const std::string& httpResponse) {
    write(client_fd, httpResponse.c_str(), httpResponse.length());
}

bool HttpServer::isShutdownCommand(const std::string& request) {
    return request.find("GET /shutdown HTTP/1.1") != std::string::npos;
}

void HttpServer::addRoute(const std::string& path, RouteHandler handler) {
    routes[path] = handler;
}

std::string HttpServer::handleRequest(const std::string& request) {
    std::istringstream iss(request);
    std::string method, path;
    iss >> method >> path;

    auto it = routes.find(path);
    if (it != routes.end()) {
        return it->second(request);
    }

    return "HTTP/1.1 404 Not Found\nContent-Type: text/plain\nContent-Length: 13\n\n404 Not Found";
}
