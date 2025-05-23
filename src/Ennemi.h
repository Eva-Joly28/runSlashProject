#pragma once
#include "Personnage.h"
#include <SFML/Graphics.hpp>
#include "Joueur.h"
#include <iostream>

class Ennemi : public Personnage
{
protected:
	float speed;
	sf::Clock clock;
	sf::CircleShape* hitbox;

public:
	Ennemi();

	void draw(sf::RenderWindow& window, const sf::Drawable* toDraw);
	void move(sf::Vector2f direction);
	sf::FloatRect gethitboxBounds();
	void attack(Joueur* cible);
	virtual void updateDir(sf::Vector2f direction) = 0;
	void updateJoueur(Joueur* cible);
};


