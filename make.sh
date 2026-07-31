#!/bin/bash

[ -d build ] && rm -rf build
cmake -S . -B build && cmake --build build && ./build/checklist.exe