#include "Loot.h"

Loot::Loot()
{
	if (!texture.loadFromFile("assets/Loot.png")) {
		
	}
	sprite.setTexture(texture);
	sprite.setPosition(position);
}

Loot::~Loot() {}

void Loot::setLootType(enum type)
{
	lootType = type;
}

enum Loot::getLootType() const
{
	return lootType;
}

void Loot::applyEffect(sf::Sprite& target)
{
	switch (lootType) {
	case ARMURE:
	
		break;
	case BAZOOKA:
		
		break;
	case PISTOLET:
		
		break;
	default:
		break;
	}
}
