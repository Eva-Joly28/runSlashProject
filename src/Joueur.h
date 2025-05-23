#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Personnage.h"
#include "Loot.h"
#include<iostream>	
#include <memory>

class Joueur : public Personnage
{
private:
	bool moveLeft, moveRight, moveUp, moveDown, turnLeft, turnRight;
	sf::Clock cooldownClock;
	sf::Time cooldownTime;
	sf::CircleShape* hitbox;

public:
	Joueur();

	sf::FloatRect gethitboxBounds();
	void addLoot(Loot *newLoot);
	int getPv();
	void update(sf::Vector2f direction);
	void handleInput(std::optional<sf::Event>* event, sf::RenderWindow* window);
	std::string updatePv();
	void updateMovement(sf::Time deltaTime, const std::vector<sf::RectangleShape>& murs);
};