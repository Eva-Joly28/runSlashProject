#pragma once
#include "Ennemi.h"
#include <SFML/Graphics.hpp>

class Boss : public Ennemi{
public:
	Boss();
	virtual ~Boss();
	
	void attack() override;
	void update(sf::Vector2f direction) override;
	void specialAttack();


};