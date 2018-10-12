cmake_minimum_required(VERSION 3.5)
project(Rage-MP-C-SDK VERSION 0.1.0 LANGUAGES CXX)

include(GNUInstallDirs)

option(BUILD_TESTS "Build sdk tests" OFF)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

if(WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MD")
endif(WIN32)

add_subdirectory(src)

if(BUILD_TESTS)
    add_subdirectory(tests)
endif(BUILD_TESTS)
