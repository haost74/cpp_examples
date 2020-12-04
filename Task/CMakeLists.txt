cmake_minimum_required(VERSION 3.2)

project(app VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/../)

SET(CMAKE_CXX_STANDARD 17)

find_package (Threads)

# Add an executable with the above sources
#hello_binary = app
add_executable(app 
    src/main.cpp src/TPool.cpp
)

target_link_libraries(app PRIVATE Threads::Threads)