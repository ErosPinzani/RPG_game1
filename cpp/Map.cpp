//
// Created by erosp on 00/00/0000.
//

#include <fstream>
#include "../h/Map.h"

Map*Map::instance= nullptr;

void Map::generatemap() {

}

Map::Map() {
    this->vectorM1 = {

    };

    std::ifstream file("Map.txt");

    while(file.good()) {
        std::string line;
        std::getline(file, line);
        for(char c : line) {
            this->vectorM1.push_back((int)c - '0');
        }
    }
}

Map *Map::getInstance() {
    if(instance == nullptr)
        instance = new Map;
    return instance;
}
