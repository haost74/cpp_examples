cmake_minimum_required(VERSION 3.2)
project(app VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


#include(${CMAKE_SOURCE_DIR}/MyStaticLibrary.a)

add_executable(app 
    src/Main.cpp src/Client.h  src/Port.cpp
)


target_link_libraries(app  PUBLIC ${CMAKE_SOURCE_DIR}/libclient.so)