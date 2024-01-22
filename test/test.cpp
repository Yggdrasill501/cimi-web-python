#include "HttpServer.h"

int main(){
    HttpServer server(5000);
    
    server.start();
    
    return 0;
}
