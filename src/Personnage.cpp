#include "Personnage.h"
#include <SFML/Graphics.hpp>


Personnage::Personnage() : pv(100), position(0.f, 0.f) {}

Personnage::~Personnage() {}

void Personnage::takeDamage(int dmg) {
    int effectiveDamage = static_cast<int>(dmg * (1.0f - resistance));
    pv -= effectiveDamage;
    if (pv < 0) pv = 0;
}

void Personnage::DropLoot() {
    // Ajouter la logique après création loot   
}

bool Personnage::isAlive() const {
    return pv > 0;
}

void Personnage::setPosition(sf::Vector2f pos) {
    position = pos;
    sprite.setPosition(position);
}

sf::Vector2f Personnage::getPosition() const {
    return position;
}

sf::Sprite Personnage::getSprite() {
    return sprite;
}
