#!/bin/bash

echo 'clean build files...'
rm -rf build/
mkdir build
cd build

echo 'start buiding project...'
cmake ..
make

mv src/main ./
echo 'Running the app'
./main
