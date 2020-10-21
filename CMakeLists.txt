cmake_minimum_required(VERSION 3.17)
project(RPG_game)

set(CMAKE_CXX_STANDARD 14)

add_executable(RPG_game main.cpp Character.cpp Character.h Bullet.cpp Bullet.h Obstacle.cpp Obstacle.h Weapon.cpp Weapon.h PowerUp.cpp PowerUp.h Hero.cpp Hero.h MeleeWeapon.cpp MeleeWeapon.h Enemy.cpp Enemy.h StWeapon.cpp StWeapon.h)