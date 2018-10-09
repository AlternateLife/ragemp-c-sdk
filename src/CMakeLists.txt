include_directories(${CMAKE_SOURCE_DIR}/include)

include_directories(${CMAKE_SOURCE_DIR}/thirdparty)

add_library(ragemp_wrapper SHARED rage.cpp multiplayer.cpp plugin.cpp eventHandler.cpp player.cpp clrHost.cpp)

set_target_properties(ragemp_wrapper PROPERTIES OUTPUT_NAME "dotnet-wrapper")
