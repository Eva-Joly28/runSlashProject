#pragma once
#include <SFML/Graphics.hpp>
#include "Personnage.h"

class Joueur : public Personnage
{
private:
	sf::Clock attackTimer;
	sf::Time coolDown;

public : 

	Joueur();
	virtual ~Joueur();


	void dropLoot() override;
	void addLoot();
	void attack() override;
};