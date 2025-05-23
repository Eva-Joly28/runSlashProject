#include "Kamikaze.h"

Kamikaze::Kamikaze() : Ennemi(), exploded(false), explosionRadius(30.f)
{
	explosionTexture.loadFromFile("assets/explosion.png");
	explosion = new Explosion(explosionTexture, sprite->getPosition());
	speed = 250.f;
	pv = 20;
	if (!texture.loadFromFile("assets//Kamikaze.png")) {
		// Handle error
	}
	sprite = new sf::Sprite(texture);
	sprite->setPosition(position);
}

void  Kamikaze::updateDir(sf::Vector2f direction) {
	if (pv > 0) {
		//sf::Vector2f direction = target->getPosition() - getPosition();
		move(direction);
	}

}

Kamikaze::~Kamikaze()
{
	delete explosion;
	delete sprite;
}

void Kamikaze::attack()
{
		//explode();
}

void Kamikaze::update(sf::Vector2f playerPosition, float deltaTime, sf::RenderWindow* window)
{
	sf::Vector2f direction = playerPosition - sprite->getPosition();
	float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);
	if (!exploded) {
		if(distance < explosionRadius){
			explode(window);
			exploded = true;
			pv = 0;
		}

	}

}

void Kamikaze::explode(sf::RenderWindow* window)
{
	// animation et logique d'explosion
	explosion->update(sf::seconds(3.0f));
	explosion->draw(*window);
	
}
