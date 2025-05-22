#include "Boss.h"

Boss::Boss(Joueur* cible) : Ennemi(cible)
{
	if (!texture.loadFromFile("assets/bossfinal.png")) {
		// a gerer
	}
	sprite = new sf::Sprite(texture);
	sprite->setPosition(position);
}
Boss::~Boss()
{
}


void Boss::attack()
{
	sf::Sprite* targetSprite = target->getSprite();
	// Logique d'attaque
	if (isAlive()) {
		if (sprite->getGlobalBounds().position.x - targetSprite->getLocalBounds().position.x <= (2.f, 2.f)) {
			 // Ou activer l'explosion après un certain temps je sais pas encore
		}
	}

}

void  Boss::update(sf::Vector2f direction){
	if (!pv) {
		sf::Vector2f direction = target->getPosition() - getPosition();
		move(direction);
	}

}

void Boss::specialAttack()
{

}
