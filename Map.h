//
// Created by erosp on 22/10/2020.
//

#ifndef RPG_GAME_MAP_H
#define RPG_GAME_MAP_H
#include <vector>

class Map {
public:
    void generatemap() = 0;

    static Map* getInstance();

    std::vector<int> vectorM1;
private:
    Map();
    static Map*instance;
};


#endif //RPG_GAME_MAP_H
