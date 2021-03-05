cmake_minimum_required(VERSION 3.17)
project(RPG_game)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(Tests)

set(Classi cpp/Entities/Character.cpp h/Entities/Character.h cpp/Projectiles/Bullet.cpp h/Projectiles/Bullet.h cpp/Chest.cpp h/Chest.h cpp/Weapon.cpp h/Weapon.h cpp/PickUpClass.cpp h/PickUpClass.h cpp/Entities/Hero.cpp h/Entities/Hero.h cpp/Projectiles/MeleeWeapon.cpp h/Projectiles/MeleeWeapon.h cpp/Entities/Enemy.cpp h/Entities/Enemy.h cpp/Projectiles/StBullet.cpp h/Projectiles/StBullet.h cpp/Projectiles/AoeBullet.cpp h/Projectiles/AoeBullet.h cpp/Map.cpp h/Map.h cpp/Tile.cpp h/Tile.h cpp/Random.cpp h/Random.h cpp/TextDisplayClass.cpp h/TextDisplayClass.h h/RenderMap.h)

add_executable(RPG_game cpp/main.cpp ${Classi} h/Functions.h)

add_library(RPG_game_Tests ${Classi})

find_package(SFML 2 COMPONENTS network audio graphics window system REQUIRED)

target_link_libraries(RPG_game sfml-graphics sfml-window sfml-system)