#include "Epeiste.h"

Epeiste::Epeiste()
{
	if (!texture.loadFromFile("assets/Epeiste.png")) {
		// Handle error
	}
	sprite->setTexture(texture);
	sprite->setPosition(position);
}
void Epeiste::fight() {
	// animation bagarre à l'épée
}
void Epeiste::attack() {
	//move();
}
void  Epeiste::update(sf::Vector2f direction) {

}
Epeiste::~Epeiste()
{
}
