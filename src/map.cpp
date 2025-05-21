#include "Map.h"
#include <SFML/Graphics.hpp>
#include <vector>

Map::Map() : mapSize(2500.f, 2000.f)
{
    textureFond.loadFromFile("assets//map.jpg");
    spriteFond = new sf::Sprite(textureFond);

    spriteFond->setScale({ 3.f,2.3f });

    spriteFond->setPosition(sf::Vector2f(0.f, 0.f));

    Create_border();

}

void Map::draw(sf::RenderWindow& window) {
    window.draw(*spriteFond);
    for (const auto& mur : murs)
    {
        window.draw(mur);
    }
}

void Map::Create_border()
{
    murs.clear();

    sf::RectangleShape mur1(sf::Vector2f(10.f, mapSize.y)); // Mur gauche
    mur1.setFillColor(sf::Color::White);
    mur1.setPosition({ 0.f, 0.f });
    murs.push_back(mur1);

    sf::RectangleShape mur2(sf::Vector2f(10.f, mapSize.y)); // Mur droit
    mur2.setFillColor(sf::Color::White);
    mur2.setPosition({ mapSize.x - 10.f, 0.f });
    murs.push_back(mur2);

    sf::RectangleShape mur3(sf::Vector2f(mapSize.x, 10.f)); // Mur supérieur
    mur3.setFillColor(sf::Color::White);
    mur3.setPosition({ 0.f, 0.f });
    murs.push_back(mur3);

    sf::RectangleShape mur4(sf::Vector2f(mapSize.x, 10.f)); // Mur inférieur
    mur4.setFillColor(sf::Color::White);
    mur4.setPosition({ 0.f, mapSize.y - 10.f });
    murs.push_back(mur4);

}

void Map::add_obstacle()
{

}
sf::Sprite* Map::getSprite()
{
    return spriteFond;
}
void Map::check_collision()
{
    return;
}

const std::vector<sf::RectangleShape>& Map::getMurs() const {
    return murs;
}

sf::Vector2f Map::getMapSize() const {
    return mapSize;
}
