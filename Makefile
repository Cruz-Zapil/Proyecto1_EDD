all: build/main

build/main: src/main.cpp
    g++ -Iinclude -o build/main src/main.cpp

clean:
    rm -rf build/*
