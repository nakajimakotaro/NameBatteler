cmake_minimum_required(VERSION 3.9)
project(nameBattler)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_VERBOSE_MAKEFILE 1)

link_directories("./")
add_executable(nameBattler
        src/main.cpp
        src/core/screen.cpp
        src/core/input.cpp
        src/core/commandManager.cpp
        src/core/game.cpp
        src/core/fps.cpp
        src/common/rect.cpp
        src/scene/scene.h
        src/scene/gameing/gameingScene.cpp
        src/asset/messageArea.cpp
        src/asset/gameObject.cpp
        src/asset/player.cpp
        )
target_link_libraries(nameBattler winmm)

