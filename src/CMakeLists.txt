cmake_minimum_required(VERSION 3.14)
project(test_clrs)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL http://139.224.58.15/zip/googletest-03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


enable_testing()

add_executable(
  test_clrs
  test_clrs.cc
)
add_library(clrs STATIC clrs.cpp)

target_link_libraries(
  test_clrs
  GTest::gtest_main
  clrs
)

include(GoogleTest)
gtest_discover_tests(test_clrs)