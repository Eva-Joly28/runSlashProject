#include "Joueur.h"

#define VITESSE 220

using  namespace std;
Joueur::Joueur() : Personnage(), moveLeft(false), moveRight(false), moveUp(false), moveDown(false), turnLeft(false), turnRight(false)
{
    hitbox = new sf::CircleShape(2.f);
    pv = 100;
	degats = 50;
	path = "assets/joueur_handgun.png";
    if (!texture.loadFromFile(path)) {
        std::cerr << "Error loading texture" << std::endl;
        return;
    }

	cooldownTime = sf::seconds(1.0f);
    sprite = new sf::Sprite(texture);
    sf::FloatRect bounds = sprite->getLocalBounds();
    sprite->setOrigin(bounds.getCenter());
    sf::Vector2f origin(98.f, 116.f);
    //sprite->setOrigin({ origin });
    hitbox->setOrigin({ origin });
    hitbox->setPosition({ 400.f, 150.f });
    sprite->setPosition({ 200.f, 150.f });
	sprite->setScale({ 0.3f,0.3f });

}

sf::FloatRect Joueur::gethitboxBounds()
{
    return hitbox->getGlobalBounds();
}

void Joueur::addLoot(Loot *newLoot) {
	if (isAlive()) {
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

//void Joueur::attack() {
//    if (cooldownClock.getElapsedTime() >= cooldownTime) {
//        cooldownClock.restart();
//
//    }
//}
void Joueur::handleInput(std::optional<sf::Event>* eventOpt, sf::RenderWindow* window)
{
    if (!eventOpt || !eventOpt->has_value())
        return;

    const sf::Event& event = eventOpt->value();

    if (event.is<sf::Event::Closed>()) {
        window->close();
    }
    else if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>()) {
        switch (keyPressed->scancode) {
        case sf::Keyboard::Scancode::Left:  moveLeft = true; break;
        case sf::Keyboard::Scancode::Right: moveRight = true; break;
        case sf::Keyboard::Scancode::Up:    moveUp = true; break;
        case sf::Keyboard::Scancode::Down:  moveDown = true; break;
        case sf::Keyboard::Scancode::G:     turnLeft = true; break;
        case sf::Keyboard::Scancode::D:     turnRight = true; break;
        default: break;
        }
    }
    else if (const auto* key = event.getIf<sf::Event::KeyReleased>()) {
        switch (key->scancode) {
        case sf::Keyboard::Scancode::Left:  moveLeft = false; break;
        case sf::Keyboard::Scancode::Right: moveRight = false; break;
        case sf::Keyboard::Scancode::Up:    moveUp = false; break;
        case sf::Keyboard::Scancode::Down:  moveDown = false; break;
        case sf::Keyboard::Scancode::G:     turnLeft = false; break;
        case sf::Keyboard::Scancode::D:     turnRight = false; break;
        default: break;
        }
    }
}


std::string Joueur::updatePv()
{
    std::string path;

    if (pv == 100)
        path = "assets//full_vie.png";
    else if (pv > 35)
        path = "assets//moins_full_vie.png";
    else if (pv > 0)
        path = "assets//presque_vide_vie.png";
    else
        path = "assets//mort_vie.png";
	return path;
}

void Joueur::updateMovement(sf::Time deltaTime, const std::vector<sf::RectangleShape> &murs)
{
    sf::Vector2f direction(0.f, 0.f);

    if (moveLeft) {  direction.x -= (VITESSE * deltaTime.asSeconds()); }
    if (moveRight)  {  direction.x += (VITESSE * deltaTime.asSeconds()); }
    if (moveUp) {  direction.y -= (VITESSE * deltaTime.asSeconds()); }
    if (moveDown) {  direction.y += (VITESSE * deltaTime.asSeconds()); }
    if (turnLeft) { sprite->rotate(sf::degrees(3)); }
    if (turnRight) { sprite->rotate(sf::degrees(-3)); }

    sf::FloatRect nextBounds = hitbox->getGlobalBounds();
    nextBounds.position.x += direction.x;
    nextBounds.position.y += direction.y;

    cout << direction.x << " ma dir" << endl;

    bool collision = false;
    for (const auto& mur : murs) {
        if (nextBounds.findIntersection(mur.getGlobalBounds())) {
            collision = true;
            cout  << " yes c'est true" << endl;
        }
    }
    if (!collision) {
        sprite->move(direction);
    }


}





