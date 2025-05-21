#include "Boss.h"

Boss::Boss()
{
	if (!texture.loadFromFile("assets/Boss.png")) {
		// a gerer
	}
	sprite = new sf::Sprite(texture);
	//sprite->setTexture(texture);
	sprite->setPosition(position);
}
Boss::~Boss()
{
}


void Boss::attack()
{

}

void  Boss::update(sf::Vector2f direction) {

}
void Boss::specialAttack()
{

}
