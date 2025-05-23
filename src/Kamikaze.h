#pragma once
#include "Ennemi.h"
#include "Joueur.h"
#include "explosion.h"
#include <SFML/Graphics.hpp>

class Kamikaze : public Ennemi
{
private:
	sf::Texture explosionTexture;
	//sf::Sprite explosionSprite;

	//Joueur* target;
	Explosion* explosion;
	bool exploded;
	float explosionRadius;
public:
	Kamikaze();
	~Kamikaze();

	void attack() ;
	void updateDir(sf::Vector2f direction) override;
	void update(sf::Vector2f playerPosition, float deltaTime, sf::RenderWindow* window) ;
	void explode(sf::RenderWindow* window);
};