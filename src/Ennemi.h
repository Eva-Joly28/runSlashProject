#pragma once
#include "Personnage.h"
#include <SFML/Graphics.hpp>
#include "Joueur.h"

class Ennemi : public Personnage
{
protected:
	Joueur* target;
	float speed;

public:
	Ennemi(Joueur* target);

	void move(sf::Vector2f direction);

	virtual void attack() = 0;
	virtual void update(sf::Vector2f direction) = 0;
};


