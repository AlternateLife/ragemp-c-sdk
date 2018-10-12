include_directories(${CMAKE_SOURCE_DIR}/include)

include_directories(${CMAKE_SOURCE_DIR}/thirdparty)

add_library(ragemp_wrapper SHARED rage.cpp multiplayer.cpp eventHandler.cpp player.cpp entity.cpp vehicle.cpp vehiclePool.cpp world.cpp pool.cpp config.cpp playerPool.cpp colshape.cpp checkpoint.cpp marker.cpp blip.cpp textLabel.cpp blipPool.cpp checkpointPool.cpp colshapePool.cpp markerPool.cpp objectPool.cpp textLabelPool.cpp utils.cpp)

set_target_properties(ragemp_wrapper PROPERTIES OUTPUT_NAME "dotnet-wrapper")

install(FILES ${CMAKE_BINARY_DIR}/src/dotnet-wrapper.dll DESTINATION "${CMAKE_SOURCE_DIR}/../RageMP Server/plugins")
