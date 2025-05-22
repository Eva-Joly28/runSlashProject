#include "Epeiste.h"

Epeiste::Epeiste(Joueur* target) : Ennemi(target)
{
	if (!texture.loadFromFile("assets//epeiste.png")) {
		// Handle error
	}
	sprite = new sf::Sprite(texture);
	sprite->setPosition(position);
}
void Epeiste::fight() {
	// animation bagarre à l'épée
}
void Epeiste::attack() {
	sf::Sprite targetSprite = *(target->getSprite());
	// Logique d'attaque
	if (isAlive()) {
		if (sprite->getGlobalBounds().position.x - targetSprite.getLocalBounds().position.x <= (2.f, 2.f)) {
			// Ajouter une animation de combat maybe
		}
	}
}
void  Epeiste::update(sf::Vector2f direction) {
	if (pv>0) {
		sf::Vector2f direction = target->getPosition() - getPosition();
		move(direction);
	}

}
Epeiste::~Epeiste()
{
}
