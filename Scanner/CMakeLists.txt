cmake_minimum_required(VERSION 3.2)
project(app VERSION 0.0.1)

set(CMAKE_CXX_STANDART 17)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package (Threads)
find_package (SQLite3)

include_directories(${SQLITE3_INCLUDE_DIRS})


add_executable(app 
    main.cpp 
)

target_link_libraries(app
     
         Threads::Threads  
          sqlite3
         #${OUT_TARGET} ${SQLite3_LIBRARIES}
)