@echo off
cls
g++ -std=c++11 -Wall -Wextra -Wfloat-equal -Wundef -Wcast-align -Wwrite-strings -Wlogical-op -Wmissing-declarations -Wredundant-decls -Wshadow -Woverloaded-virtual -o main.exe .\Implementations\*.cpp .\main.cpp 

