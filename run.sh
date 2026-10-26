#!/bin/bash
g++-15 -std=gnu++23 -O2 -Wall "$1" -o a && ./a <input.txt
