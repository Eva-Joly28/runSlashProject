#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Personnage
{
protected:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f position;

	int pv;
	int resistance = 0;
	int degats = 0;

public:
	Personnage();
	virtual ~Personnage();

	void Attack();
	void update(float action);
	void takeDamage(int damage);
	void DropLoot();
	bool isAlive() const;

	void setPosition(sf::Vector2f pos);
	sf::Vector2f getPosition() const;
	sf::Sprite getSprite();


};


