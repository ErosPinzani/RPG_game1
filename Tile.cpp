//
// Created by erosp on 22/10/2020.
//

#include "Tile.h"

const std::string &Tile::getType() const {
    return type;
}

void Tile::setType(const std::string &type) {
    Tile::type = type;
}

bool Tile::isWalkable() const {
    return walkable;
}

void Tile::setWalkable(bool walkable) {
    Tile::walkable = walkable;
}
