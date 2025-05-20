#pragma once
#include Personnage.h
#include <SFML/Graphics.hpp>

class Ennemi : public Personnage
{
private:
	int speed;

public:
	Ennemi();
	virtual ~Ennemi();
	void move(float deltaTime);
}

