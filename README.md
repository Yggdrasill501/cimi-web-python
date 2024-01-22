# Cimi Web
A C/C++ micro framework for building web applications.

The idea is to create minimastic framework in c++ and CMake to make it as easy as possible.
The framework must handle Servers and Web Sockets.
And be as easy to use and possible with simple download to be used

## Motivation
U may ask where is the motivation comming from? Its comming to understand and to handle the best way how to handle back-end and api development, 
and since C/C++ is porobably the most abstract way to do it your self.

## Simple Web server
In [Simple Socket](https://github.com/Yggdrasill501/cimi-web/blob/main/simple_websocket/simple_socket.c), I used simple implentation of server that retrun on ***local host port 8000*** message I am web server.
I used also some modules from standard library to make it as easy as possible to implent just as showcase a to reminder how "Cimple" it can be to handle server. 
### Run simple socket
1. Compile using:
```
gcc -o server server.c
```
2. To execute:
```
./server
```
