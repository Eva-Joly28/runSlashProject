#include "explosion.h"

Explosion::Explosion(sf::Texture image, sf::Vector2f position)
{
	explosionSprite = new sf::Sprite(image);
	explosionTimer = 0.f;
	cols = 5; 
	rows = 5;
    const int frameWidth = image.getSize().x / cols;
    const int frameHeight = image.getSize().y / rows;

    frames.resize(rows, std::vector<sf::IntRect>(cols));
    for (int y = 0; y < rows; ++y) {
        for (int x = 0; x < cols; ++x) {
            frames[y][x] = sf::IntRect(
                sf::Vector2i(x * frameWidth, y * frameHeight),
                sf::Vector2i(frameWidth, frameHeight)
            );
        }
    }

	explosionSprite->setTextureRect(frames[currentRow][currentFrame]);
	explosionSprite->setPosition(position);
	explosionSprite->setScale({ 0.5f, 0.5f });
}

void Explosion::update(sf::Time dureeIteration)
{
	explosionTimer += dureeIteration.asSeconds();
	if (explosionTimer >= 0.1f) {
		explosionTimer = 0.f;
		currentFrame++;
		if (currentFrame >= cols) {
			currentFrame = 0;
			currentRow++;
			if (currentRow >= rows) {
				currentRow = 0;
				exploded = true;
			}
		}
		explosionSprite->setTextureRect(frames[currentRow][currentFrame]);
	}
}

void Explosion::draw(sf::RenderWindow& window)
{
	window.draw(*explosionSprite);
}

bool Explosion::isExploded() const
{
	return exploded;
}
