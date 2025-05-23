#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Explosion
{
private:
	sf::Texture explosionImage;
	sf::Sprite* explosionSprite;
	sf::Clock explosionClock;
	sf::Vector2f position;
	float explosionTimer;
	int cols, rows;
	int currentFrame, currentRow;
	bool exploded;
	std::vector<std::vector<sf::IntRect>> frames;
public:
	Explosion(sf::Texture image, sf::Vector2f position );
	void update(sf::Time dureeIteration);
	void draw(sf::RenderWindow& window);
	bool isExploded() const;
	
};
