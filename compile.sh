#!/bin/bash

day="$1"
problem="$2"

if [ -z $day ]; then
    echo "Day not specified."
    exit 1
fi

if [ -z $problem ]; then
    echo "Problem not specified."
    exit 1
fi

mkdir -p ./build/day-$day

echo "Compiling day-$day :: problem $problem"

if ! clang++ -std=c++20 -o ./build/day-$day/$problem ./day-$day/$problem.cpp; then
    echo "Failed to compile"
    exit 1
fi

./build/day-$day/$problem
