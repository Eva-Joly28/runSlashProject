#include "Ennemi.h"

Ennemi::Ennemi(Joueur* cible) : Personnage(), target(cible), speed(100)
{

}


void Ennemi::move(sf::Vector2f direction)
{
	/*float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
	if (length != 0)
		direction /= length;*/

	sf::Vector2f deplacement = direction * speed ;
	sprite->move(deplacement);
}

