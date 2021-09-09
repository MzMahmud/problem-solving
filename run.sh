#!/bin/bash

echo "compiling $1..."
g++ -std=c++17 $1

echo "running a.exe..."
./a.exe