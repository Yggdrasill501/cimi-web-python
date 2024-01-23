# Cimi Web
A C/C++ micro framework for building web applications.

The idea is to create minimalistic framework in c++ and CMake to make it as easy as possible.
The framework must handle Servers and Web Sockets.
And be as easy to use and possible with simple download to be used

## How to run
To run server just execute [shell script](https://github.com/Yggdrasill501/cimi-web/blob/main/server.sh)
```
server.sh
```
If you're having struggle running server.sh, don't forget to gave it correct permission.
```
chmod +x server.sh
```

## Motivation
U may ask where is the motivation coming from? It's coming to understand and to handle the best way how to handle back-end and api development, 
and since C/C++ is probably the most abstract way to do it your self.

## Simple Web server
In [Simple Socket](https://github.com/Yggdrasill501/cimi-web/blob/main/simple_websocket/simple_socket.c), 
I used simple implementation of server that run on ***local host port 8000*** message I am web server.
I used also some modules from standard library to make it as easy as possible to implement just as showcase a to 
reminder how "Cimple" it can be to handle server. 

### Run simple socket
1. Compile using:
```
gcc -o server server.c
```
2. To execute:
```
./server
```

## What should micro framework implement ?
After implementing http response into browser on any ip, in my case [localhost 8000](http://localhost:8000/), 
implementing basic reading of html and implementing it into framework and closing connection after making 
response on http://localhost:8000/shutdown (for debugging purposes), I kinda struggled what next to implement and 
because we are in 2024 I asked ChatGPT what should micro framework have and for now 
I will make from it little to-do list:

- [ ] Routing: A routing system to handle incoming HTTP requests and direct them to the appropriate controller or endpoint.
- [ ] Middleware: Support for middleware functions to perform tasks like authentication, logging, request/response processing, and more.
- [ ] Request and Response Handling: Capability to handle and parse incoming HTTP requests and generate appropriate HTTP responses.
- [ ] Controllers/Handlers: A mechanism for defining and organizing request handlers or controllers to process and respond to incoming requests.
- [ ] Database Integration: The ability to interact with databases, with support for common database management tasks like querying, connecting, and migrating.
- [ ] Authentication and Authorization: Basic authentication and authorization mechanisms to secure endpoints and restrict access to certain resources.
- [ ] Error Handling: A mechanism to handle errors gracefully and return meaningful error responses to clients.
- [ ] Dependency Injection: Optional support for dependency injection to manage dependencies and promote modularity.
- [ ] Testing Support: Built-in or easily integratable testing utilities and frameworks for unit and integration testing.
- [ ] Logging: Logging capabilities for tracking application activity and debugging purposes.
- [ ] Configuration: Configuration management for setting environment-specific variables and parameters.
- [ ] Validation: Input validation and data validation mechanisms to ensure data integrity and security.
- [ ] API Documentation: Tools or utilities to generate API documentation, making it easier for developers to understand and use the API.
- [ ] Middleware Extensibility: The ability to add custom middleware to extend the functionality of the framework.
- [ ] Performance: Optimizations to ensure good performance, such as caching, asynchronous processing, and scalability options.
- [ ] Security Features: Basic security features like Cross-Origin Resource Sharing (CORS) handling, input sanitization, and protection against common security vulnerabilities.
- [ ] Support for Various Data Formats: Ability to handle different data formats, such as JSON, XML, and others, for both request and response payloads.
- [ ] File Upload Handling: Support for handling file uploads if required by your application.
- [ ] Routing Parameters: Support for dynamic routing parameters and URL parameters.
- [ ] Extensibility: A way to extend or customize the framework's functionality based on the specific needs of the application.

I realise I won't be able to use all of it but lets just how far I can get.

## BTW
Motivation of this project was to make it as simple as possible, and simplicity is always found in minimalism, so for whole project I was using neovim, and if you wish to see my simple config visit [Neovim Setup](https://github.com/Yggdrasill501/yggdrasill501_nvim_setup).
After this I can say "I USE NEOVIM BTW!!!"
And for the future motivation I will implement this on my Raspberry PI, using arch and pacman, so I can say "I USE ARCHLINUX BTW"
