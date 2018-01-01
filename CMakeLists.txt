cmake_minimum_required(VERSION 3.9)
project(nameBattler)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_VERBOSE_MAKEFILE 1)

link_directories("./")
add_executable(nameBattler
        src/main.cpp
        src/core/screen.cpp
        src/core/game.cpp
        src/core/fps.cpp
        src/common/rect.cpp
        src/common/state.h
        src/common/stateMachine.h
        src/asset/gameObject.h
        src/asset/messageArea.cpp
        src/asset/player.cpp
        src/asset/playerJumpState.cpp
        src/asset/playerRunState.cpp
        src/scene/scene.h
        src/scene/inputManager.cpp
        src/scene/gameing/gameingScene.cpp
        src/scene/gameing/gameingInputManager.cpp
        src/asset/camera.cpp src/asset/camera.h)
target_link_libraries(nameBattler winmm)

