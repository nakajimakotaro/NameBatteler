cmake_minimum_required(VERSION 3.9)
project(nameBattler CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_VERBOSE_MAKEFILE 1)

link_directories("./")
add_executable(nameBattler
        src/main.cpp
        src/core/screen.cpp
        src/core/game.cpp
        src/core/fps.cpp
        src/common/json.h
        src/common/rect.cpp
        src/common/state.h
        src/common/stateMachine.h
        src/common/gameObject.h
        src/asset/messageArea.cpp
        src/asset/player.cpp
        src/asset/playerJumpState.cpp
        src/asset/playerRunState.cpp
        src/scene/scene.h
        src/scene/inputManager.cpp
        src/scene/gameing/gameingScene.cpp
        src/scene/gameing/gameingInputManager.cpp
        src/asset/camera.cpp src/asset/camera.h
        src/asset/block.cpp src/asset/block.h
        src/asset/debugMessage.cpp src/asset/debugMessage.h
        src/common/collision.cpp src/common/collision.h
        src/common/collider.cpp src/common/collider.h
        src/asset/playerFallState.cpp src/asset/playerFallState.h
        src/asset/enemy.cpp src/asset/enemy.h
        src/asset/playerDamageState.cpp src/asset/playerDamageState.h
        src/common/gameObject.cpp
        src/asset/particle.cpp src/asset/particle.h
        src/asset/moveParticle.cpp src/asset/moveParticle.h
        src/asset/bullet.h
        src/asset/whipBullet.cpp src/asset/whipBullet.h
        src/asset/dotBullet.cpp src/asset/dotBullet.h
        src/asset/arrowBullet.cpp src/asset/arrowBullet.h
        src/scene/start/startScene.cpp src/scene/start/startScene.h
        src/scene/scene.cpp src/asset/nameInput.cpp
        src/asset/nameInput.h
        src/asset/moveBlock.cpp src/asset/moveBlock.h
        src/asset/EnemyBullet.cpp src/asset/EnemyBullet.h src/asset/goal.cpp src/asset/goal.h src/scene/end/endScene.cpp src/scene/end/endScene.h)
target_link_libraries(nameBattler winmm)

