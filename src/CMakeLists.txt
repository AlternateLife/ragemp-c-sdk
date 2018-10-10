include_directories(${CMAKE_SOURCE_DIR}/include)

include_directories(${CMAKE_SOURCE_DIR}/thirdparty)

add_library(ragemp_wrapper SHARED rage.cpp multiplayer.cpp plugin.cpp eventHandler.cpp player.cpp clrHost.cpp entity.cpp vehicle.cpp vehiclePool.cpp clrPlugin.cpp world.cpp)

set_target_properties(ragemp_wrapper PROPERTIES OUTPUT_NAME "dotnet-wrapper")

install(FILES ${CMAKE_BINARY_DIR}/src/dotnet-wrapper.dll DESTINATION "${CMAKE_SOURCE_DIR}/../RageMP Server/plugins")
