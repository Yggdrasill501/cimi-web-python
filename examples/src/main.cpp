//
// Created by Filip Žitný on 02/02/2024.
//
#include <server/server.h>
#include <iostream>
#include <client/client.h>


//// For Server listening
int main() {
    try {
        Server server;
        server.runServer();
    } catch (const std::runtime_error& e) {
        std::cerr << "Failed to start the server: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

//// For Client connection
//int main() {
//    Client client;
//
//    if (!client.connectToServer(8080, "127.0.0.1")) {
//        std::cerr << "Connection to server failed." << std::endl;
//        return 1;
//    }
//
//    std::cout << "Connected to the server successfully." << std::endl;
//
//    client.sendMessage("Hello, server! This is the client.");
//
//
//    return 0;
//}

