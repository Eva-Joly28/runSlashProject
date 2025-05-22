#pragma once
#include <SFML/Graphics.hpp>
#include "Loot.h"
#include <vector>

class Personnage
{
protected:
	sf::Texture texture;
	sf::Sprite* sprite;
	sf::Vector2f position;
	std::vector<Loot> inventaire;

	int pv;
	float resistance = 0.f;
	int degats = 0;

public:
	Personnage();

	virtual void update(sf::Vector2f direction) = 0;
	virtual void attack() = 0; 

	void takeDamage(int damage);
	std::vector<Loot> DropLoot();
	bool isAlive() const;

	void setPosition(sf::Vector2f pos);
	void setResistance(float res);
	sf::Vector2f getPosition() const;
	sf::Sprite* getSprite();

};


