#include "Joueur.h"

#define SPEED 100.f


Joueur::Joueur() : Personnage() {
    if (!texture.loadFromFile("assets//joueur.png")) {
		std::cerr << "Error loading texture" << std::endl;
        return;
        
    }
	cooldownTime = sf::seconds(0.5f);
    sprite = new sf::Sprite(texture);
	sprite->setTexture(texture);
	sprite->setPosition(position);
	sprite->setScale({ 0.5f,0.7f });

}

void Joueur::addLoot(Loot *newLoot) {
	if (Joueur::isAlive()) {
		inventaire.push_back(*newLoot);
	}

}

int Joueur::getPv()
{
	return this->pv;
}

void Joueur::update(sf::Vector2f direction)
{
    sprite->move(direction);
}

void Joueur::attack() {
	if (cooldownClock.getElapsedTime() >= cooldownTime) {
		// Animation d'attaque
		cooldownClock.restart();
	}
}
/*
static void switchPressedKey(bool isPressed, sf::Event::KeyPressed key) {
    switch (key.scancode)
    {
        case sf::Keyboard::Scancode::Left:
            moveleft = isPressed;
            break;
        case sf::Keyboard::Scancode::Right:
            moveright = isPressed;
            break;
        case sf::Keyboard::Scancode::Up:
            moveup = isPressed;
            break;
        case sf::Keyboard::Scancode::Down:
            movedown = isPressed;
            break;
    }
}
*/


void Joueur::walking() {
    /*
    if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
    {
        switchPressedKey(true, keyPressed);
    }
    else if (const auto* keyPressed = event->getIf<sf::Event::KeyReleased>())
    {
        switchPressedKey(false, keyPressed);
    }
    */
}


