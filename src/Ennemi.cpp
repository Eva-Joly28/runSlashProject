#include "Ennemi.h"

Ennemi::Ennemi()
{
	if (!texture.loadFromFile("assets/Ennemi.png")) {
<<<<<<< Updated upstream
		
	}
	sprite = new sf::Sprite(texture);
	//sprite.setTexture(texture);
	sprite->setPosition(position);
=======
		// Handle error
	}
	sprite.setTexture(texture);
	sprite.setPosition(position);
	speed = 100; // Set a default speed
}
Ennemi::~Ennemi() {}

void Ennemi::move(float deltaTime)
{
	// Move the enemy in a random direction
	float dx = (rand() % 3 - 1) * speed * deltaTime; // Random x movement
	float dy = (rand() % 3 - 1) * speed * deltaTime; // Random y movement
	position.x += dx;
	position.y += dy;
	sprite.setPosition(position);
>>>>>>> Stashed changes
}

Ennemi::~Ennemi(){}

void Ennemi::move(sf::Vector2f direction)
{
	/*float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
	if (length != 0)
		direction /= length;*/

	sf::Vector2f deplacement = direction * speed ;
	sprite->move(deplacement);
}

