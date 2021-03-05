//
// Created by erosp on 08/12/2020.
//

#ifndef MAIN_CPP_RENDERMAP_H
#define MAIN_CPP_RENDERMAP_H

#include <SFML/Graphics.hpp>
#include <exception>

class RenderMap : public sf::Drawable, public sf::Transformable, public std::exception {
protected:
    int *map;
    sf::VertexArray vertices;
    sf::Texture texture;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        states.transform = getTransform();         // apply the transform
        states.texture = &texture;                  // apply the tiles texture
        target.draw(vertices, states);              // draw the vertex array
    }
public:
    static std::vector<std::vector<int>> enemyPos;
    static std::vector<std::vector<int>> chestPos;
    int map_width = 48;
    int map_height = 21;

    RenderMap() {};
    void generate(sf::Vector2u tileSize, std::vector <int> tiles, int width, int height) noexcept(false) {
        // load the tiles texture
        if(!texture.loadFromFile(R"(Resources\Images.jpg)")){
            throw std::runtime_error("File not found");
        }

        // resize the vertex array to fit the level size
        vertices.setPrimitiveType(sf::Quads);
        vertices.resize(width * height * 4);    // rgba

        // populate the vertex array, with one quad per tile
        int tile_number, tile, tu, tv;

        for(int i = 0; i < width; i++) {
            for(int j = 0; j < height; j++) {

                // get the current tile number
                tile = tiles[i + j * width];
                tile_number = tile;
                // find its position in the tileset texture
                tu = tile_number % (texture.getSize().x / tileSize.x);
                tv = tile_number / (texture.getSize().x / tileSize.x);

                // get a pointer to the current tile's quad
                sf::Vertex *quad = &vertices[(i + j * width) * 4];

                // define its 4 corners
                quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
                quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
                quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
                quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

                // define its 4 texture coordinates
                quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
                quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
                quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
                quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
            }
        }
    }
};

std::vector<std::vector<int>> RenderMap::enemyPos =  std::vector<std::vector<int>> ({
    std::vector<int>({501, 453}), std::vector<int>({501, 453}),
    std::vector<int>({391, 678}), std::vector<int>({391, 678}),
    std::vector<int>({1056, 718}), std::vector<int>({1056, 718}),
    std::vector<int>({916, 968}), std::vector<int>({916, 968}),
    std::vector<int>({236, 908}), std::vector<int>({236, 908}),
    std::vector<int>({106, 388}), std::vector<int>({106, 388}),
    std::vector<int>({1456, 968}), std::vector<int>({1456, 968}),
    std::vector<int>({2316, 718}), std::vector<int>({2316, 718}),
    std::vector<int>({1561, 633}), std::vector<int>({1561, 633}),
    std::vector<int>({526, 53}), std::vector<int>({526, 53}),
    std::vector<int>({766, 358}), std::vector<int>({766, 358}),
    std::vector<int>({1351, 518}), std::vector<int>({1351, 518}),
    });

std::vector<std::vector<int>> RenderMap::chestPos = std::vector<std::vector<int>> ({
    std::vector<int>({371, 563}),
    std::vector<int>({61, 363}),
    std::vector<int>({1271, 953}),
    std::vector<int>({1526, 568}),
    std::vector<int>({366, 53}),
    });

#endif //MAIN_CPP_RENDERMAP_H
