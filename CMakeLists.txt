cmake_minimum_required(VERSION 3.10)

# Set your project name
project(CimiServer)

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
    src/server.cpp
        src/server.cpp
        src/cimi/socket/socket.h
        src/cimi/socket/socket.cpp
)

# Add executable
add_executable(CimiServer ${SOURCES}
       src/server.cpp

)

file(COPY ${CMAKE_SOURCE_DIR}/src/index.html DESTINATION ${CMAKE_BINARY_DIR})
