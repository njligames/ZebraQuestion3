#!/bin/bash

rm -rf build
mkdir build
cd build

export CC=gcc export CXX=g++
cmake ../
make

./ZebraQuestion3

