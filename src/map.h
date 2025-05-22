#pragma once

#include <SFML/Graphics.hpp>
#include <vector>


class Map {

private:

    sf::Vector2f mapSize;
    sf::Texture textureFond;
    sf::Sprite* spriteFond;
    std::vector<sf::RectangleShape> murs;


public:

    Map();
    void draw(sf::RenderWindow& window);

    //crée des Bordures

    void Create_border();

    //crée des murs ou des obstacles dans la map 

    void add_obstacle();

    sf::Sprite* getSprite();

    // checks la collision 

    void check_collision();

    const std::vector<sf::RectangleShape>& getMurs() const;
    sf::Vector2f getMapSize() const;

};
