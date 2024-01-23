#ifndef WEBSOCKETSERVER_H
#define WEBSOCKETSERVER_H


#include <vector>
#include "WebSocketConnetion.h"

class WebSocketServer {
public:
    WebSocketServer(int port);

    // Start the server
    void start();

    // Stop the server
    void stop();

private:
    // Method to accept connections
    void acceptConnection();

    // Server port
    int port;

    // List of active connections
    std::vector<WebSocketConnection> connections;

    // Server socket...
};

#endif // WEBSOCKETSERVER_H

