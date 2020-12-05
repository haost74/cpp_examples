cmake_minimum_required(VERSION 3.6)

project(MyStaticLibrary)

set(SOURCE_FILES "MyStaticLibrary.cpp")

add_library(MyStaticLibrary STATIC ${HEADER_FILES} ${SOURCE_FILES})