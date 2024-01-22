#ifndef WEBSOCKETCONNECTION_H
#define WEBSOCKETCONNECTION_H

#include "WebSocketFrame.h"
#include <string>
#include <vector>

class WebSocketConnection {
public:
    // Establish a connection, perform handshake, etc.
    void connect(const std::string& host, int port);

    // Send a message
    void sendMessage(const std::string& message);

    // Receive a message
    std::string receiveMessage();

    // Close the connection
    void close();

private:
    // Utility methods for handshake and frame handling
    void performHandshake();
    void sendFrame(const WebSocketFrame& frame);
    WebSocketFrame receiveFrame();

    // TCP socket-related members...
};

#endif // WEBSOCKETCONNECTION_H

