cmake_minimum_required(VERSION 3.10)

# Set your project name
project(CimiServer)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()


# Include directories
include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_SOURCE_DIR}/src/cimi)

# Source files
set(SOURCES 
    src/server.cpp
        src/cimi/HttpServer/HttpServer.cpp
        src/cimi/HttpRequest/HttpRequest.cpp
        src/cimi/HttpResponse/HttpResponse.h
        src/cimi/HttpResponse/HttpResponse.cpp
        src/cimi/WebSocket/WebSocket.h
        src/cimi/WebSocket/WebSocketConnetion.h
        src/cimi/WebSocket/WebSocketServer.h
        src/cimi/WebSocket/WebSocketFrame.h
)

# Add executable
add_executable(CimiServer ${SOURCES}
        src/cimi/HttpRequest/HttpRequest.cpp
        src/cimi/HttpResponse/HttpResponse.h
        src/cimi/WebSocket/WebSocket.h
        src/cimi/WebSocket/WebSocketConnetion.h
        src/cimi/WebSocket/WebSocketServer.h)

file(COPY ${CMAKE_SOURCE_DIR}/src/index.html DESTINATION ${CMAKE_BINARY_DIR})
