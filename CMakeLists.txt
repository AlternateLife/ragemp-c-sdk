cmake_minimum_required(VERSION 3.8)
project(Rage-MP-C-SDK VERSION 1.0.0 LANGUAGES CXX)

include(GNUInstallDirs)

option(BUILD_TESTS "Build sdk tests" OFF)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

if(MSVC)
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MD")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MD")
endif()

add_subdirectory(src)

if(BUILD_TESTS)
    add_subdirectory(tests)
endif(BUILD_TESTS)
