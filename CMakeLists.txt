cmake_minimum_required(VERSION 3.30)
project(ADA)

set(CMAKE_CXX_STANDARD 14)

# Archivos fuente
set(SOURCES
        Graph.h
        bin3.h
        bin3.cpp
        Graph.cpp
        grafos.cpp
        Node.h
        Node.cpp
)

# Crear el ejecutable como una aplicación de consola
add_executable(ADA ${SOURCES})
