#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Personnage.h"
#include "Loot.h"

class Joueur : public Personnage
{
private:
	sf::Clock cooldownClock;
	sf::Time cooldownTime;

public:
	Joueur();

	void addLoot(Loot *newLoot);
	int getPv();
	void update(sf::Vector2f direction) override;
	void attack() override;
	void walking();
};