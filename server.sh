#!/bin/bash

cd "$(dirname "$0")"

mkdir -p build && cd build

echo "Running CMake..."
cmake ..

echo "Compiling the project..."
make

if [ $? -eq 0 ]; then
    echo "Compilation successful. Running the server..."
   ./CimiServer
else
    echo "Compilation failed."
fi
