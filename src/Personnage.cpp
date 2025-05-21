#include "Personnage.h"
#include <SFML/Graphics.hpp>


Personnage::Personnage() : pv(100), position(0.f, 0.f), sprite(texture), inventaire() {
}


void Personnage::takeDamage(int dmg) {
    int effectiveDamage = static_cast<int>(dmg * (1.0f - resistance));
    pv -= effectiveDamage;
    if (pv < 0) pv = 0;
}

std::vector<Loot> Personnage::DropLoot() {
    // Rajouter l'animation du dropLoot ici ou perso secifique ???
	if (!this->isAlive()) {
		return inventaire;
	}
}

bool Personnage::isAlive() const {
    return pv > 0;
}

void Personnage::setPosition(sf::Vector2f pos) {
    position = pos;
    sprite.setPosition(position);
}

void Personnage::setResistance(float res)
{
	resistance = res;
}

sf::Vector2f Personnage::getPosition() const {
    return sprite.getPosition();
}

sf::Sprite* Personnage::getSprite() {
    return &sprite;
}
