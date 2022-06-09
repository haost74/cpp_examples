cmake_minimum_required(VERSION 3.2)
project(test)

set(CMAKE_CXX_STANDARD 20)

include_directories(${GTEST_INCLUDE_DIRS})


include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  test
  test.cc
)
target_link_libraries(
  test
  gtest_main
  gmock_main
)

include(GoogleTest)
gtest_discover_tests(test)