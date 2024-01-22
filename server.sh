#!/bin/bash

# Compile the server
g++ -std=c++17 -o server src/server.cpp

# Check if the compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful. Running the server..."
    ./server
else
    echo "Compilation failed."
fi

