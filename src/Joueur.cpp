#include Joueur.h

Joueur::Joueur() : Personnage(), coolDown(sf::seconds(1.f)) {
	if (!texture.loadFromFile("assets/Player.png")) {
		// Handle error
	}
	sprite.setTexture(texture);
	sprite.setPosition(position);
}
Joueur::~Joueur() {}

void Joueur::addLoot() {
	if (Joueur::isAlive()) {
		// Logic to add loot
	}
}

void Joueur::attack() {
	if (attackTimer.getElapsedTime() >= coolDown) {
		// Logic to attack
		attackTimer.restart();
	}
}
void Joueur::dropLoot() {
	if (Joueur::isAlive()) {
		// Logic to drop loot
	}
}