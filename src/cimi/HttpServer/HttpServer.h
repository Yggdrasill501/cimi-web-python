#ifndef HTTPSERVER_H
#define HTTPSERVER_H

#include <netinet/in.h>
#include <string>
#include <functional>
#include <map>
#include <sstream>

class HttpServer {
public:
    explicit HttpServer(int port);
    void startServer();

    using RouteHandler = std::function<std::string(const std::string&)>;
    void addRoute(const std::string& path, RouteHandler handler);

private:
    int server_fd;
    int port;
    struct sockaddr_in address{};

    std::map<std::string, RouteHandler> routes;

    bool shouldShutdown(const std::string& request);
    std::string getHtmlContent(const std::string& filepath);
    int acceptNewConnection();
    std::string readRequest(int client_fd);
    void sendResponse(int client_fd, const std::string& httpResponse);
    std::string handleRequest(const std::string& request);
    bool isShutdownCommand(const std::string& request);
};

#endif // HTTPSERVER_H

