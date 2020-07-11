cmake_minimum_required(VERSION 3.15)
project(asteroids)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/CMake_module")

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
        src/Start_game.cpp
        src/bullets/Bullet_graphics_component.h
        src/bullets/Bullet_input_component.h
        src/bullets/Bullet_physics_component.h
        src/bullets/Bullet_graphics_component.cpp
        src/bullets/Bullet_input_component.cpp
        src/bullets/Bullet_physics_component.cpp
        src/images/Texture_shelf.h
        src/scenes/Avoid_asteroids_scene.h
        src/scenes/Control_spaceships_scene.h
        src/scenes/Destroy_asteroids_scene.h
        src/scenes/Two_spaceships_scene.h
        src/scenes/Scene.h
        src/shared/Game_object.h
        src/shared/Game_object_meta.h
        src/shared/Game_object_motion.h
        src/init/Constants.h
        src/shared/Graphics.h
        src/shared/Graphics_component.h
        src/shared/Input_component.h
        src/shared/Object_name.h
        src/shared/Physics_component.h
        src/spaceship/Spaceship1_graphics_component.h
        src/spaceship/Spaceship1_input_component.h
        src/spaceship/Spaceship1_physics_component.h
        src/spaceship/Spaceship2_graphics_component.h
        src/spaceship/Spaceship2_input_component.h
        src/spaceship/Spaceship2_physics_component.h
        src/init/SDL2_lib.h
        src/text/Render_text.h
        src/shared/Game_object_utils.h
        src/debug_info/Frames_debug_info.h
        src/debug_info/Graphics_debug_info.h
        src/debug_info/Objects_debug_info.h
        src/debug_info/Frames_debug_info.cpp
        src/debug_info/Graphics_debug_info.cpp
        src/debug_info/Objects_debug_info.cpp
        src/images/Texture_shelf.cpp
        src/init/SDL2_lib.cpp
        src/scenes/Destroy_asteroids_scene.cpp
        src/shared/Game_object.cpp
        src/shared/Game_object_utils.cpp
        src/shared/Graphics_component.cpp
        src/shared/Physics_component.cpp
        src/text/Render_text.cpp src/spaceship/Spaceship1_graphics_component.cpp src/spaceship/Spaceship2_graphics_component.cpp src/spaceship/Spaceship1_input_component.cpp)

add_compile_options(-Wall -Wextra -Wpedantic -Werror)
target_link_libraries(asteroids ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2_TTF_LIBRARY})
target_compile_options(asteroids PUBLIC -Wall -Wextra -Werror)

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_definitions(asteroids PUBLIC "RELEASE")
endif ()
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(asteroids PUBLIC "DEBUG")
endif ()

