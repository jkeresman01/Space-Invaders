cmake_minimum_required(VERSION 3.10)
project(SpaceInvaders)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

include_directories(src/headers)

set(SOURCE_FILES
    src/ResourceManager.cpp
    src/Spaceship.cpp
    src/Bullet.cpp
    src/Animation.cpp
    src/Enemy.cpp
    src/Main.cpp
)

add_executable(space-invaders ${SOURCE_FILES})

target_link_libraries(space-invaders sfml-graphics sfml-window sfml-system sfml-audio)

add_custom_command(TARGET space-invaders POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/src/resources $<TARGET_FILE_DIR:space-invaders>/resources
)
