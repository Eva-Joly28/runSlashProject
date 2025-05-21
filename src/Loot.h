#pragma once
#include <SFML/Graphics.hpp>


typedef enum LootType {
	ARMURE,
	BAZOOKA,
	PISTOLET
} LootType;

class Loot {
private:
	sf::Clock cooldown;
	LootType type ;
	int degats;
	
public:
	Loot();
	void setLootType(LootType type);
	LootType getLootType() const;
	
	void switchDegats();
};



