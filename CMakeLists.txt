cmake_minimum_required(VERSION 3.10)

project(Cimi-Web VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${PROJECT_SOURCE_DIR}/src/cimi)

file(GLOB SOURCES "src/cimi/*.cpp")

add_executable(Cimi-Web ${SOURCES})

