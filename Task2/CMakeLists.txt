cmake_minimum_required(VERSION 3.2)
project(app)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")
find_package (Threads)

add_subdirectory(src)
add_subdirectory(test)

add_executable(app main.cpp)

target_link_libraries(app task Threads::Threads)