cmake_minimum_required(VERSION 3.17)
project(RPG_game)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(Tests)

set(Classi Character.cpp Character.h Bullet.cpp Bullet.h Chest.cpp Chest.h Weapon.cpp Weapon.h PickUp.cpp PickUp.h Hero.cpp Hero.h MeleeWeapon.cpp MeleeWeapon.h Enemy.cpp Enemy.h StBullet.cpp StBullet.h AoeBullet.cpp AoeBullet.h Map.cpp Map.h Tile.cpp Tile.h Random.cpp Random.h TextDisplayClass.cpp TextDisplayClass.h RenderMap.h)

add_executable(RPG_game main.cpp ${Classi})

add_library(RPG_game_Tests ${Classi})

find_package(SFML 2 COMPONENTS network audio graphics window system REQUIRED)

target_link_libraries(RPG_game sfml-graphics sfml-window sfml-system)