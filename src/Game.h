#pragma once
#include<SFML/Graphics.hpp>
#include <memory>
#include "map.h"
#include "Joueur.h"
#include "Kamikaze.h"
#include "Epeiste.h"
#include "Boss.h"
#include "Ennemi.h"
#include <iostream>



class Game {
public:
	Game();
	void run();
	void handleEvents();
	void update(sf::Time deltaTime);
	void render();
private:
	std::string pathBarreVie;
	sf::Texture textureBarreVie;
	sf::Sprite* spriteBarreVie;
	sf::RenderWindow window;
	sf::Clock clock;
	sf::Time deltaTime;
	sf::View view;

	std::vector<std::unique_ptr<Ennemi>> ennemis;
	Joueur player;
	Map map;
	bool moveLeft, moveRight, moveUp, moveDown, turnLeft, turnRight;
};