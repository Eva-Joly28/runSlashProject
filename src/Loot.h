#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


typedef enum LootType {
	ARMURE,
	BAZOOKA,
	PISTOLET
} LootType;

class Loot {
private:
	sf::Texture texture;
	sf::Sprite* sprite;
	std::string path;	
	sf::Clock cooldown;
	LootType type;
	int degats;

public:
	Loot(int degats);
	void setLootType(LootType type);
	LootType getLootType() const;
	void setPath(const std::string& newPath);
	std::string getPath() const;
	void move(sf::Vector2f direction);
	void draw(sf::RenderWindow & window);
	
	//void switchDegats();
};



