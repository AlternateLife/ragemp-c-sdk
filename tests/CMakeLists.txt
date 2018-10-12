project(RageMP_C_Tests LANGUAGES C)

add_executable(test_executable main.c)

target_link_libraries(test_executable PRIVATE ragemp_c_sdk)
