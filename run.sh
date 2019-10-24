#!/bin/bash
cmake --build "build" --config Release --target all -- -j 10
./Program

rm Program