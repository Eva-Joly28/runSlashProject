#pragma once
#include <SFML/Graphics.hpp>

class Loot {
private:
	sf : Clock coolDown;
	LootType type ;
	
public:
	Loot();
	~Loot();
	void setLootType(LootType type);
	int getLootType() const;
	
	void applyEffect(sf::Sprite& target);
	
};

enum LootType {
	ARMURE,
	BAZOOKA,
	PISTOLET
};
