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
	// animation bagarre � l'�p�e
}
void Epeiste::attack() {
	//move();
}
void  Epeiste::update(sf::Vector2f direction) {

}
Epeiste::~Epeiste()
{
}
