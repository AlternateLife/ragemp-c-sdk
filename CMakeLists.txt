cmake_minimum_required(VERSION 3.5)
project(Rage-MP-C-SDK VERSION 0.1.0 LANGUAGES CXX)

include(GNUInstallDirs)

option(BUILD_TESTS "Build sdk tests" OFF)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

if(MSVC)
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MD /EHa")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MD /EHa")
endif()

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")

endif()

add_subdirectory(src)

if(BUILD_TESTS)
    add_subdirectory(tests)
endif(BUILD_TESTS)
