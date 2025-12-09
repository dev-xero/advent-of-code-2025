#!/bin/bash

day="$1"

if [ -z $day ]; then
    echo "Day not specified."
    exit 1
fi

mkdir day-$day
touch day-$day/a.cpp
touch day-$day/b.cpp
touch day-$day/test.txt
touch day-$day/input.txt

cat template.cpp > day-$day/a.cpp
cat template.cpp > day-$day/b.cpp
