#pragma once
#include "Ennemi.h"
#include "Joueur.h"
#include <SFML/Graphics.hpp>

class Kamikaze : public Ennemi
{
private:
	//sf::Texture explosionTexture;
	//sf::Sprite explosionSprite;

	//Joueur* target;
	bool exploded = false;
	float explosionRadius = 50.f;
	float speed = 180.f;
public:
	Kamikaze(Joueur* target);
	virtual ~Kamikaze();

	void attack() ;
	void update(sf::Vector2f direction) ;
	void explode();
};