cmake_minimum_required(VERSION 3.10)
project(NODProject)

set(CMAKE_CXX_STANDARD 11)

find_package(GTest REQUIRED)

add_library(nod_lib include/nod.h src/nod.cpp)
target_include_directories(nod_lib PUBLIC include)

add_executable(nod_main src/main.cpp)
target_link_libraries(nod_main nod_lib)

add_executable(nod_tests test/tests_nod.cpp)
target_link_libraries(nod_tests nod_lib GTest::GTest GTest::Main)

include(GoogleTest)
gtest_discover_tests(nod_tests)