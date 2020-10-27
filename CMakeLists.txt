cmake_minimum_required(VERSION 3.15)
project(asteroids)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_find")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIR})

include_directories(src)
include_directories(src/bullets)
include_directories(src/images)
include_directories(src/scenes)
include_directories(src/shared)
include_directories(src/spaceship)

configure_file(resources/background_01_static.jpg ./resources/background_01_static.jpg COPYONLY)
configure_file(resources/bullet_short_single.png ./resources/bullet_short_single.png COPYONLY)
configure_file(resources/DKO-api-X1.png ./resources/DKO-api-X1.png COPYONLY)
configure_file(resources/CX16-X1.png ./resources/CX16-X1.png COPYONLY)
configure_file(resources/WO84-wu-X1.png ./resources/WO84-wu-X1.png COPYONLY)
configure_file(resources/terminus.ttf ./resources/terminus.ttf COPYONLY)
configure_file(resources/explosion.png ./resources/explosion.png COPYONLY)

add_executable(asteroids
        src/start_game.cpp
        src/images/texture_shelf.h
        src/scenes/destroy_asteroids_scene.h
        src/shared/obj_meta.h
        src/shared/obj_motion.h
        src/init/constants.h
        src/shared/obj_name.h
        src/init/sdl2_util.h
        src/text/render_text.h
        src/debug_info/frames_debug.h
        src/debug_info/graphics_debug.h
        src/debug_info/objects_debug.h
        src/debug_info/frames_debug.cpp
        src/debug_info/graphics_debug.cpp
        src/debug_info/objects_debug.cpp
        src/images/texture_shelf.cpp
        src/init/sdl2_util.cpp
        src/scenes/destroy_asteroids_scene.cpp
        src/text/render_text.cpp
        src/bullets/bullet.cpp src/bullets/bullet.h src/spaceship/spaceship.cpp src/spaceship/spaceship.h src/shared/gfx_helpers.cpp src/shared/gfx_helpers.h src/shared/physics_helpers.cpp src/shared/physics_helpers.h)

add_compile_options(-Wall -Wextra -Wpedantic -Werror)
target_link_libraries(asteroids ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2_TTF_LIBRARY})
target_compile_options(asteroids PUBLIC -Wall -Wextra -Werror)

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_definitions(asteroids PUBLIC "RELEASE")
endif ()
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(asteroids PUBLIC "DEBUG")
endif ()

