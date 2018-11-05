set(TARGET_NAME ragemp_c_sdk)
set(SOURCES rage.cpp multiplayer.cpp eventHandler.cpp player.cpp entity.cpp vehicle.cpp vehiclePool.cpp world.cpp pool.cpp config.cpp playerPool.cpp
        colshape.cpp checkpoint.cpp marker.cpp blip.cpp textLabel.cpp blipPool.cpp checkpointPool.cpp colshapePool.cpp markerPool.cpp objectPool.cpp
        textLabelPool.cpp utils.cpp plugin.cpp)

add_library(${TARGET_NAME} STATIC ${SOURCES})

target_include_directories(${TARGET_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
target_include_directories(${TARGET_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../thirdparty)
