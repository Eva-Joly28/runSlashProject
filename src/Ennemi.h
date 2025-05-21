#include "Personnage.h"
#include <SFML/Graphics.hpp>

class Ennemi : public Personnage
{
private:
	float speed;

public:
	Ennemi();

	void move(sf::Vector2f direction);

	virtual void attack() = 0;
	virtual void update(sf::Vector2f direction) = 0;
};


