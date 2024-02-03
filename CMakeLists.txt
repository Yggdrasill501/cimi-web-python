cmake_minimum_required(VERSION 3.10)

# Set your project name
project(CimiWeb)

# C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()


# Include directories
include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_SOURCE_DIR}/src/cimi)

# Source files
set(SOURCES
        src/cimi/socket/socket.h
        src/cimi/socket/socket.cpp
        src/cimi/handler/html_handler.cpp
        src/cimi/handler/html_handler.h
        examples/src/main.cpp
        examples/src/main.cpp
        src/cimi/server/server.cpp
        src/cimi/server/server.h
        src/cimi/client/client.cpp
        src/cimi/client/client.h
        src/app.cpp
        src/app.h
        src/wapper.cpp
)

# Add executable
add_executable(CimiWeb ${SOURCES}
        examples/src/main.cpp

)

configure_file(${PROJECT_SOURCE_DIR}/examples/public/index.html ${CMAKE_CURRENT_BINARY_DIR}/index.html COPYONLY)
