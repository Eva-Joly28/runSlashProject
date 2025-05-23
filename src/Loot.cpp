#include "Loot.h"

Loot::Loot(int hurt) : degats(hurt)
{
	path = "assets/balle_s.png";
	if (!texture.loadFromFile(path)) {
		std::cerr << "Error loading texture" << std::endl;
		return;
	}
	sprite = new sf::Sprite(texture);
	sf::FloatRect bounds = sprite->getLocalBounds();
	sprite->setOrigin({ (bounds.size.x) / 2.f ,bounds.size.y });
	sprite->setScale({ 0.3f,0.3f });

}

void Loot::setLootType(LootType type)
{
	this->type = type;
}


LootType Loot::getLootType() const
{
	return type;
}

std::string Loot::getPath() const
{
	return path;
}

void Loot::move(sf::Vector2f direction)
{
	sprite->move(direction);
}

void Loot::draw(sf::RenderWindow& window)
{
	window.draw(*sprite);
	
}

void Loot::setPath(const std::string& newPath)
{
	path = newPath;
	/*if (!texture.loadFromFile(path)) {
		std::cerr << "Error loading texture" << std::endl;
		return;
	}
	sprite->setTexture(texture);*/
}

//void Loot::switchDegats()
//{
//	switch (type) {
//	case ARMURE:
//		//float res = 0.2f;
//		//target->setResistance(res);
//		break;
//	case BAZOOKA:
//		degats = 40;
//		//target->takeDamage(degats);
//		break;
//	case PISTOLET:
//		degats = 20;
//		//target->takeDamage(degats);
//		break;
//	default:
//		break;
//	}
//}
