#ifndef WEB_SOCKET_H
#define WEB_SOCKET_H

#include <string>

class WebSocket {
public:
    // Constructor, destructor, and other necessary functions

    void send(const std::string& message);
    std::string receive();

    // Additional WebSocket-specific methods...
};

#endif // WEB_SOCKET_H
