#include "Boss.h"

Boss::Boss() : Ennemi()
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
	//Pas la bonne m�thode d'attaque, temporaire
	pv = 0;

}

void  Boss::updateDir(sf::Vector2f direction){
	if (!pv) {
		//sf::Vector2f direction = target->getPosition() - getPosition();
		move(direction);
	}

}

void Boss::specialAttack()
{

}
