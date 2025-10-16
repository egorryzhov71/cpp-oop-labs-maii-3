cmake_minimum_required(VERSION 3.16)
project(lab2 VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(include)

add_executable(lab2
    src/fivee.cpp
    main.cpp
)

option(BUILD_TESTS "Build tests" ON)

if(BUILD_TESTS)
    enable_testing()
    
    include(FetchContent)
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
    )
    
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)
    
    add_executable(tests_fivee
        tests/tests_fivee.cpp
        src/fivee.cpp
    )
    
    target_link_libraries(tests_fivee
        GTest::gtest_main
    )
    
    add_test(NAME FiveTests COMMAND tests_fivee)
endif()