#include "cimi/HttpServer/HttpServer.h"

int main() {
    HttpServer server(8000);
    server.startServer();
    return 0;
}

