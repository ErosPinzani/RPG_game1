//
// Created by erosp on 22/10/2020.
//

#ifndef RPG_GAME_TILE_H
#define RPG_GAME_TILE_H
#include <string>
#include "Map.h"

class Tile: public Map {
public:
    void generatemap() override;

    const std::string &getType() const;

    void setType(const std::string &type);

    bool isWalkable() const;

    void setWalkable(bool walkable);

private:
    std::string type;
    bool walkable;
};


#endif //RPG_GAME_TILE_H
