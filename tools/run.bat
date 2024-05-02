@echo off

echo Ejecutando CMake...
cmake -B build
cd build

echo Compilando con Make...
make

echo Ejecutando el programa...
./main

cd ..

