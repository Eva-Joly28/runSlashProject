#include "Kamikaze.h"

Kamikaze::Kamikaze(Joueur* target) : Ennemi(target)
{
	if (!texture.loadFromFile("assets//Kamikaze.png")) {
		// Handle error
	}
	sprite->setTexture(texture);
	sprite->setPosition(position);
}

Kamikaze::~Kamikaze()
{
}

void Kamikaze::attack()
{
	sf::Sprite* targetSprite = target->getSprite();
	// Logique d'attaque
	if (isAlive()) {
		if (sprite->getGlobalBounds().position.x - targetSprite->getLocalBounds().position.x <= (2.f, 2.f)) {
			explode(); // Ou activer l'explosion après un certain temps je sais pas encore
		}
	}
	else {
		explode();
	}
}

void Kamikaze::update(sf::Vector2f direction)
{
	if (!exploded) {
		sf::Vector2f direction = target->getPosition() - getPosition();
		move(direction);

	}
	
}

void Kamikaze::explode()
{
	// animation et logique d'explosion
	exploded = true;
	pv = 0;
}
