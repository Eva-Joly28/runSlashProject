#pragma once
#include "Ennemi.h"
#include "Joueur.h"
#include "Personnage.h"

class Epeiste : public Ennemi
{
	//sf::Texture texture;
	//sf::Sprite* sprite;
	//Joueur* target;
public:
	Epeiste();

	void updateDir(sf::Vector2f direction);
	void fight();
};
