#pragma once

#include "Ennemi.h"

class Epeiste : public Ennemi
{
public:
	Epeiste();
	virtual ~Epeiste();

	void attack() override;
	void update(sf::Vector2f direction) override;
	void fight();
};
