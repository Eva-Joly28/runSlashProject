#pragma once
#include "Ennemi.h"
#include <SFML/Graphics.hpp>
#include "Joueur.h"

class Boss : public Ennemi{
public:
	Boss(Joueur* cible);
	virtual ~Boss();
	
	void attack();
	void update(sf::Vector2f direction);
	void specialAttack();


};