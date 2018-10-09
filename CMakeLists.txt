cmake_minimum_required(VERSION 3.5)
project(Rage-MP-C-SDK VERSION 0.1.0 LANGUAGES CXX)

include(GNUInstallDirs)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_subdirectory(src)
add_subdirectory(tests)
