#include <SFML/Graphics.hpp>
#include "map.h"
#include "Joueur.h"
#include "Kamikaze.h"
#include "Epeiste.h"
#include "Boss.h"

#define VITESSE 120

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({ 900, 700 }), "Run & Slash");
    window.setFramerateLimit(60);

    Map map; 
    sf::Sprite* spriteMap = map.getSprite();

    Joueur player1;
    sf::Sprite* spritePlayer1 = player1.getSprite();
    spritePlayer1->setOrigin({(spritePlayer1->getGlobalBounds().size.x)/2 ,(spritePlayer1->getGlobalBounds().size.y) / 2 });
    spritePlayer1->setPosition({ 200.f, 150.f });
   

    Kamikaze kamikaze(&player1);
    sf::Sprite* spriteKamikaze = kamikaze.getSprite();
   
    spriteKamikaze->rotate(sf::degrees(180));
    spriteKamikaze->setScale({ 0.9f, 0.9f });
    spriteKamikaze->setPosition({ 100.f, 300.f });

	Epeiste epeiste(&player1);
    sf::Sprite* spriteEpeiste = epeiste.getSprite();
    //spriteEpeiste->setRotation(sf::degrees(90));
    spriteEpeiste->setScale({ 0.9f, 0.9f });
    spriteEpeiste->setPosition({ 100.f, 200.f });

    Boss boss(&player1);
    sf::Sprite* spriteBoss = boss.getSprite();


    sf::Texture textureBarreVie;
    if (!textureBarreVie.loadFromFile("assets//full_vie.png")) {
        return -1;
    }
	sf::Sprite* spriteBarreVie = new sf::Sprite(textureBarreVie);
	spriteBarreVie->setScale({ 3.0f, 3.0f });
	spriteBarreVie->setPosition({ 670.f, 35.f });

    bool moveleft = false, moveright = false, moveup = false, movedown = false, turnleft = false, turnright = false;

    sf::Clock clock;
    sf::Time deltaTime = sf::Time::Zero;

    sf::View vue(sf::FloatRect({ 0.f, 0.f }, { 400.f, 300.f }));

    while (window.isOpen())
    {
        deltaTime = clock.restart();
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                switch (keyPressed->scancode)
                {
                case sf::Keyboard::Scancode::Escape:
                    window.close();
                    break;
                case sf::Keyboard::Scancode::Left:
                    moveleft = true;
                    break;
                case sf::Keyboard::Scancode::Right:
                    moveright = true;
                    break;
                case sf::Keyboard::Scancode::Up:
                    moveup = true;
                    break;
                case sf::Keyboard::Scancode::Down:
                    movedown = true;
                    break;
                case sf::Keyboard::Scancode::G:
                    turnleft = true;
                    break;
                case sf::Keyboard::Scancode::D:
                    turnright = true;
                    break;
                }
            }
            else if (const auto* key = event->getIf<sf::Event::KeyReleased>())
            {
                switch (key->scancode)
                {
                case sf::Keyboard::Scancode::Left:
                    moveleft = false;
                    break;
                case sf::Keyboard::Scancode::Right:
                    moveright = false;
                    break;
                case sf::Keyboard::Scancode::Up:
                    moveup = false;
                    break;
                case sf::Keyboard::Scancode::Down:
                    movedown = false;
                    break;
                case sf::Keyboard::Scancode::G:
                    turnleft = false;
                    break;
                case sf::Keyboard::Scancode::D:
                    turnright = false;
                    break;
                
                }
            }
        }

		int pv = player1.getPv();
		if (pv == 100) {
            if (!textureBarreVie.loadFromFile("assets//full_vie.png")) {
                return -1;
            }
            spriteBarreVie->setTexture(textureBarreVie);
		}
		else if (pv < 100 && pv>25) {
            if (!textureBarreVie.loadFromFile("assets//moins_full_vie.png")) {
                return -1;
            }
            spriteBarreVie->setTexture(textureBarreVie);
		}
        else if (pv <= 25 && pv != 0) {
            if (!textureBarreVie.loadFromFile("assets//presque_vide_vie.png")) {
                return -1;
            }
            spriteBarreVie->setTexture(textureBarreVie);
        }
		else if (pv == 0) {
            if (!textureBarreVie.loadFromFile("assets//mort_vie.png")) {
				return -1;
            }
			spriteBarreVie->setTexture(textureBarreVie);
		}


        sf::Vector2f direction(0.f, 0.f);
        if (moveleft) {
            spritePlayer1->setRotation(sf::degrees(180));
            direction.x -= (VITESSE * deltaTime.asSeconds());
        }
        if (moveright) {
            
            spritePlayer1->setRotation(sf::degrees(0));
            direction.x += VITESSE * deltaTime.asSeconds();

        }
        if (moveup) {
            
            spritePlayer1->setRotation(sf::degrees(270));
            direction.y -= VITESSE * deltaTime.asSeconds();
        }
        if (movedown) {
            
            spritePlayer1->setRotation(sf::degrees(90));
            direction.y += VITESSE * deltaTime.asSeconds();
        }
		if (turnleft) {
			spritePlayer1->rotate(sf::degrees(3));
		}
        if (turnright) {
            spritePlayer1->rotate(sf::degrees(-3));
        }
        spritePlayer1->move(direction);

        sf::Vector2f centreVue = spritePlayer1->getPosition() + spritePlayer1->getScale();


        sf::FloatRect nextBounds = spritePlayer1->getGlobalBounds();
        nextBounds.position.x += direction.x;
        nextBounds.position.y += direction.y;


        sf::Vector2f mapSize = map.getMapSize();

        if (centreVue.x < 200.f) centreVue.x = 200.f;
        if (centreVue.x > mapSize.x - 200.f) centreVue.x = mapSize.x - 200.f;
        if (centreVue.y < 150.f) centreVue.y = 150.f;
        if (centreVue.y > mapSize.y - 150.f) centreVue.y = mapSize.y - 150.f;

        vue.setCenter(centreVue);
        bool collision = false;
        for (const auto& mur : map.getMurs())
        {
            if (nextBounds.findIntersection(mur.getGlobalBounds()))
            {
                collision = true;
                break;
            }
        }
        if (!collision)
        {
            player1.update(direction);
        }
        window.setView(vue);
        window.clear();

        map.draw(window);
        window.draw(*spritePlayer1);
		window.draw(*spriteKamikaze);
		window.draw(*spriteEpeiste);
        window.setView(window.getDefaultView());
        window.draw(*spriteBarreVie);

        window.display();
    }

    return 0;
}
