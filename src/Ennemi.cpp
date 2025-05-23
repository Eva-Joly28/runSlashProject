#include "Ennemi.h"

Ennemi::Ennemi() : Personnage()
{
	hitbox = new sf::CircleShape(3.f);
	speed = speed * (pv/100.f);

}


void Ennemi::draw(sf::RenderWindow& window, const sf::Drawable* toDraw)
{
	window.draw(*toDraw);
}

void Ennemi::move(sf::Vector2f direction)
{
	/*float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
	if (length != 0)
		direction /= length;*/

	//sf::Vector2f deplacement = direction * speed ;
	//sprite->move(deplacement);
}

sf::FloatRect Ennemi::gethitboxBounds()
{
	return hitbox->getGlobalBounds();
}

void Ennemi::attack(Joueur* Joueur) {
	if (this->isAlive()) {
		Joueur->takeDamage(degats);
	}
}

void Ennemi::updateJoueur(Joueur* cible)
{
	sf::Vector2f dirVec = cible->getSprite()->getPosition() - sprite->getPosition();

	float mag = std::sqrt(dirVec.x * dirVec.x) + (dirVec.y * dirVec.y);
	float dirAngleRad = -std::atan2(dirVec.x, dirVec.y);

	
	float time = clock.getElapsedTime().asSeconds();
	if(time>=0.02f){
		sprite->setRotation(sf::radians(dirAngleRad));
		sprite->move(time * speed * dirVec / mag);
	}
	clock.restart();
}

