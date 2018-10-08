project(RageMP_C_Tests LANGUAGES C)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(wrapper_test main.c)

target_link_libraries(wrapper_test ragemp_wrapper)
