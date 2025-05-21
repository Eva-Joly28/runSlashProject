#include <SFML/Graphics.hpp>
#include <vector>
#include "Joueur.h"
#include "Map.h"

#define VITESSE_DEPLACEMENT 120
int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({700, 600}), "Run & Slash");
    window.setFramerateLimit(60);

    Map map;

    Joueur player1;
    sf::Sprite* spritePlayer1 = player1.getSprite();

    /*sf::RenderTexture* myText = new sf::RenderTexture(sf::Vector2u(20, 20));
    myText->clear(sf::Color::Red);
    sf::Sprite test(myText->getTexture());

    test.setPosition({ 200.f, 150.f });*/

    spritePlayer1->setScale({ 50.0f, 70.0f });
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
        // Passer en paramètre via le main peut-être
        if (moveleft) { direction.x -= (VITESSE_DEPLACEMENT * deltaTime.asSeconds()); }
        if (moveright) { direction.x += (VITESSE_DEPLACEMENT * deltaTime.asSeconds());}
        if (moveup) { direction.y -= (VITESSE_DEPLACEMENT * deltaTime.asSeconds()); }
        if (movedown) { direction.y += (VITESSE_DEPLACEMENT * deltaTime.asSeconds()); }
        // Collision
        sf::FloatRect nextBounds = spritePlayer1->getGlobalBounds();
        nextBounds.position.x += direction.x;
        nextBounds.position.y += direction.y;

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
            //std::cout << direction.x  << "," << direction.y << std::endl;
            player1.update(direction);
            //test.move(direction);
        }
        
        // Mise à jour de la vue
        sf::Vector2f centreVue = spritePlayer1->getPosition() +spritePlayer1->getScale();

        sf::Vector2f mapSize = map.getMapSize();

        if (centreVue.x < 200.f) centreVue.x = 200.f;
        if (centreVue.x > mapSize.x - 200.f) centreVue.x = mapSize.x - 200.f;
        if (centreVue.y < 150.f) centreVue.y = 150.f;
        if (centreVue.y > mapSize.y - 150.f) centreVue.y = mapSize.y - 150.f;

        //vue.setCenter(centreVue);
        window.setView(vue);

        window.clear();
        map.draw(window);
        window.draw(*spritePlayer1);
        //window.draw(test);
      
        

        window.display();
     }

    return 0;
}
