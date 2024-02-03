//
// Created by Filip Žitný on 03/02/2024.
//

#include "app.h"
#include "server/server.h"
#include "client/client.h"
#include "iostream"
#include <thread>

void App::runServer() {
    Server server;
    try {
        server.runServer();
    } catch (const std::exception& e) {
        std::cerr << "Server exception: " << e.what() << std::endl;
    }
}


void App::runClient() {
    std::this_thread::sleep_for(std::chrono::seconds(1));

    Client client;
    if (client.connectToServer(8080, "127.0.0.1")) {
        std::cout << "Client connected to server successfully." << std::endl;
        client.sendMessage("Hello from client!");
    } else {
        std::cerr << "Client failed to connect to server." << std::endl;
    }
}

void App::run() {
    std::thread serverThread(&App::runServer, this);
    std::thread clientThread(&App::runClient, this);

    serverThread.join();
    clientThread.join();
}