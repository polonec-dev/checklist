#!/bin/bash

[ -d build-windows ] && rm -rf build-windows
~/git/mxe/usr/bin/x86_64-w64-mingw32.static-cmake -S . -B build-windows -DCMAKE_BUILD_TYPE=Release && cmake --build build-windows --parallel