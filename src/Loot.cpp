#include "Loot.h"

Loot::Loot()
{

}

void Loot::setLootType(LootType type)
{
	this->type = type;
}


LootType Loot::getLootType() const
{
	return type;
}

void Loot::switchDegats()
{
	switch (type) {
	case ARMURE:
		//float res = 0.2f;
		//target->setResistance(res);
		break;
	case BAZOOKA:
		degats = 40;
		//target->takeDamage(degats);
		break;
	case PISTOLET:
		degats = 20;
		//target->takeDamage(degats);
		break;
	default:
		break;
	}
}
