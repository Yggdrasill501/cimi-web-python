cmake_minimum_required(VERSION 3.10)

project(CimiServer VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${PROJECT_SOURCE_DIR}/src/cimi)

set(SOURCES 
    src/cimi/HttpServer.cpp
    src/cimi/HttpRequest.cpp
    src/cimi/HttpResponse.cpp
    src/cimi/WebSocketFrame.cpp
    src/cimi/WebSocketConnection.cpp
    src/cimi/WebSocketServer.cpp
    test/test.cpp
)

add_executable(CimiServer ${SOURCES})

find_package(Threads REQUIRED)
target_link_libraries(CimiServer PRIVATE Threads::Threads)
