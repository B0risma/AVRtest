#!/bin/sh
mkdir build 2> /dev/null
cd build
cmake ../ && cmake --build ./ --target generateHex