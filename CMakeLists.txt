cmake_minimum_required(VERSION 3.9)
project(nameBattler)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_VERBOSE_MAKEFILE 1)

link_directories("./")
add_executable(nameBattler
        src/main.cpp
        src/screen.cpp
        src/screen.h
        src/input.cpp
        src/input.h
        src/commandManager.cpp
        src/depth.cpp
        src/messageArea.cpp
        src/rect.cpp
        src/game.cpp
        src/scene.h src/fps.cpp src/fps.h src/level.cpp src/level.h src/noneScene.cpp src/noneScene.h)
target_link_libraries(nameBattler winmm)

