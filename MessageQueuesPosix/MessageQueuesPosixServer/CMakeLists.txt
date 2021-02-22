cmake_minimum_required(VERSION 3.2)

project(app)

#set(CMAKE_BUILD_TYPE Release)
set(CMAKE_BUILD_TYPE Debug)


set(CMAKE_CXX_STANDART 17)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")


set(LIBRT "-lrt")

find_package (Threads)
find_package (SQLite3)

find_package(X11 REQUIRED)

find_package(OpenCV 4.2 REQUIRED)

add_executable(app 
    src/main.cpp  
)
#INCLUDE_DIRECTORIES( ${CMAKE_CURRENT_SOURCE_DIR}/include )
include_directories(${Cairo_INCLUDE_DIRS})
target_link_libraries(app
     
         Threads::Threads  
          sqlite3
          ${X11_LIBRARIES}
           ${OpenCV_LIBS}
           ${LIBRT}
)