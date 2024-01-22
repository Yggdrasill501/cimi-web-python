#include <iostream>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main() {
    int server_fd, new_socket;
    long valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("In socket");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8000);

    memset(address.sin_zero, '\0', sizeof address.sin_zero);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("In bind");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 10) < 0) {
        perror("In listen");
        exit(EXIT_FAILURE);
    }

    while (1) {
        std::cout << "\n+++++++ Waiting for new connection ++++++++\n\n";
        std::cout << "\n+++++++ Open web site at http://localhost:8000/ ++++++++\n\n";

        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("In accept");
            exit(EXIT_FAILURE);
        }

        char buffer[30000] = {0};
        valread = read(new_socket, buffer, 30000);
        std::cout << "Received request:\n" << buffer << std::endl;

        std::string response = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 15\n\nI am web server";
        write(new_socket, response.c_str(), response.length());
        std::cout << "Response sent\n";
        close(new_socket);        
    }
    return 0;
}

