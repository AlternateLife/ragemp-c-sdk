project(RageMP_C_Tests LANGUAGES C)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(test_executable main.c)

target_link_libraries(test_executable ragemp_wrapper)
