#include <SFML/Graphics.hpp>
#include "map.h"
#include "Joueur.h"

#define VITESSE 120

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({700, 600}), "CMake SFML Project");
    window.setFramerateLimit(60);

    Map map;
    sf::Sprite* spriteMap = map.getSprite();

    Joueur player1;
    sf::Sprite* spritePlayer1 = player1.getSprite();
    sf::Vector2u tailleTexture = spritePlayer1->getTexture().getSize();
    float scaleX = 100.f / tailleTexture.x;
    float scaleY = 150.f / tailleTexture.y;
    spritePlayer1->setScale({ scaleX, scaleY });
    spritePlayer1->setPosition({ 200.f, 150.f });

    bool moveleft = false, moveright = false, moveup = false, movedown = false;

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
                }
            }
        }

        sf::Vector2f direction(0.f, 0.f);
        if (moveleft) {
            spritePlayer1->setRotation(sf::degrees(180));
            direction.x -= (VITESSE * deltaTime.asSeconds());
        }
        if (moveright) {
            spritePlayer1->setRotation(sf::degrees(-180));
            direction.x += VITESSE * deltaTime.asSeconds();

        }
        if (moveup) {
            spritePlayer1->setRotation(sf::degrees(90));
            direction.y -= VITESSE * deltaTime.asSeconds();
        }
        if (movedown) {
            spritePlayer1->setRotation(sf::degrees(-90));
            direction.y += VITESSE * deltaTime.asSeconds();
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
            player1->update(collision);
        }
        window.setView(vue);
        window.clear();

        map.draw(window);
		window.draw(*spritePlayer1);
		
		window.display();
	}

    return 0;
}
