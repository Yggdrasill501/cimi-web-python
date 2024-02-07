//
// Created by Filip Žitný on 02/02/2024.
//
#include <app.h>
#include <server/server.h>
#include <iostream>

int main() {
    App app;
    app.run();
    return 0;
}

//int main() {
//    try {
//        Server server;
//        server.runServer();
//    } catch (const std::runtime_error& e) {
//        std::cerr << "Failed to start the server: " << e.what() << std::endl;
//        return 1;
//    }
//
//    return 0;
//}