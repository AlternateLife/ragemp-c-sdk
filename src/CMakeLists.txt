include_directories(${CMAKE_SOURCE_DIR}/include)

include_directories(${CMAKE_SOURCE_DIR}/thirdparty)

add_library(ragemp_wrapper SHARED rage.cpp wrapper/multiplayer.cpp plugin.cpp eventHandler.cpp wrapper/player.cpp clrHost.cpp wrapper/entity.cpp wrapper/vehicle.cpp wrapper/vehiclePool.cpp clrPlugin.cpp wrapper/world.cpp wrapper/pool.cpp wrapper/config.cpp wrapper/playerPool.cpp wrapper/colshape.cpp wrapper/checkpoint.cpp wrapper/marker.cpp wrapper/blip.cpp wrapper/textLabel.cpp)

set_target_properties(ragemp_wrapper PROPERTIES OUTPUT_NAME "dotnet-wrapper")

install(FILES ${CMAKE_BINARY_DIR}/src/dotnet-wrapper.dll DESTINATION "${CMAKE_SOURCE_DIR}/../RageMP Server/plugins")
