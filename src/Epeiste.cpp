#include "Epeiste.h"

Epeiste::Epeiste() : Ennemi()
{
	if (!texture.loadFromFile("assets//epeiste.png")) {
		// Handle error
	}
	speed = 120.f;
	degats = 25;
	sprite = new sf::Sprite(texture);
	sf::Vector2f origin(107.f, 135.f);
	sf::FloatRect bounds = sprite->getLocalBounds();
	sprite->setOrigin({ bounds.size.x * 0.8f, bounds.size.y * 0.95f });
	//sprite->setOrigin({ origin });
	hitbox->setOrigin({ origin });
	hitbox->setPosition({ origin });
	sprite->setPosition(position);
}
void Epeiste::fight() {
	// animation bagarre à l'épée
}

void  Epeiste::updateDir(sf::Vector2f direction) {
	if (pv>0) {
		//sf::Vector2f direction = target->getPosition() - getPosition();
		move(direction);
	}

}
