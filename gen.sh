#!/bin/bash

day="$1"

if [ -z $day ]; then
    echo "Day not specified."
    exit 1
fi

mkdir day-$day
touch day-$day/a.cpp
touch day-$day/b.cpp
