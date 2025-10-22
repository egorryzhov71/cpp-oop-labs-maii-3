cmake_minimum_required(VERSION 3.10)
project(FiguresLab)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(figures_program
    main.cpp
    src/TRS.cpp
)
add_executable(figures_tests
    tests/tests_figures_simple.cpp
    src/TRS.cpp
)
target_include_directories(figures_program PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_include_directories(figures_tests PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
find_package(GTest REQUIRED)
target_link_libraries(figures_tests GTest::GTest GTest::Main)

if(UNIX)
    target_link_libraries(figures_tests pthread)
endif()

enable_testing()
add_test(NAME FiguresTests COMMAND figures_tests)