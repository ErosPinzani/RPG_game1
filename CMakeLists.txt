cmake_minimum_required(VERSION 3.17)
project(RPG_game)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(Tests)

add_executable(RPG_game main.cpp Character.cpp Character.h Bullet.cpp Bullet.h Obstacle.cpp Obstacle.h Weapon.cpp Weapon.h PowerUp.cpp PowerUp.h Hero.cpp Hero.h MeleeWeapon.cpp MeleeWeapon.h Enemy.cpp Enemy.h StBullet.cpp StBullet.h AoeBullet.cpp AoeBullet.h Map.cpp Map.h Tile.cpp Tile.h Random.cpp Random.h TextDisplay.cpp TextDisplay.h Tests/mainTests.cpp RenderMap.h)

add_library(RPG_game_Tests main.cpp Character.cpp Character.h Bullet.cpp Bullet.h Obstacle.cpp Obstacle.h Weapon.cpp Weapon.h PowerUp.cpp PowerUp.h Hero.cpp Hero.h MeleeWeapon.cpp MeleeWeapon.h Enemy.cpp Enemy.h StBullet.cpp StBullet.h AoeBullet.cpp AoeBullet.h Map.cpp Map.h Tile.cpp Tile.h Random.cpp Random.h TextDisplay.cpp TextDisplay.h)

find_package(SFML 2 COMPONENTS network audio graphics window system REQUIRED)

target_link_libraries(RPG_game sfml-graphics sfml-window sfml-system)