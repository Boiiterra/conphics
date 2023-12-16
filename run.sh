#!/bin/bash

clang -Wall -o main.o main.c -g perlin.c && ./main.o && rm main.o
