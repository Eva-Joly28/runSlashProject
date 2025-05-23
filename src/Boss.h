#pragma once
#include "Ennemi.h"
#include <SFML/Graphics.hpp>
#include "Joueur.h"

class Boss : public Ennemi{
public:
	Boss();
	virtual ~Boss();
	
	void attack();
	void updateDir(sf::Vector2f direction);
	void specialAttack();


};