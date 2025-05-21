#include "Ennemi.h"

Ennemi::Ennemi()
{
	if (!texture.loadFromFile("assets/Ennemi.png")) {
		// Erreur
	}
	sprite = new sf::Sprite(texture);
	sprite->setPosition(position);
	//sprite->setTexture(texture);
	sprite->setPosition(position);
	speed = 100; 
}


void Ennemi::move(sf::Vector2f direction)
{
	/*float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
	if (length != 0)
		direction /= length;

	sf::Vector2f deplacement = direction * speed ;
	sprite->move(deplacement);*/
}

