#include <SFML/Graphics.hpp>
#include <vector>
#include "Map.h"

#define VITESSE_DEPLACEMENT 120

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 1800, 900 }), "Run & Slash !");
    window.setFramerateLimit(60);

    Map map;

    sf::CircleShape* cercle_courant = new sf::CircleShape(25.f);
    cercle_courant->setFillColor(sf::Color::Green);
    cercle_courant->setPosition({ 200.f, 150.f });

    std::vector<sf::Drawable*> mes_cercles;
    mes_cercles.push_back(cercle_courant);

    bool moveleft = false, moveright = false, moveup = false, movedown = false;

    sf::Clock clock;
    sf::Time dureeIteration = sf::Time::Zero;

    sf::View vue(sf::FloatRect({ 0.f, 0.f }, { 400.f, 300.f }));

    while (window.isOpen())
    {
        dureeIteration = clock.restart();

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
                case sf::Keyboard::Scancode::Space:
                    cercle_courant = new sf::CircleShape(25.f);
                    cercle_courant->setFillColor(sf::Color::Red);
                    cercle_courant->setPosition({ 200.f, 150.f });
                    mes_cercles.push_back(cercle_courant);
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

        // Déplacement
        sf::Vector2f movement(0.f, 0.f);
        if (moveleft) movement.x -= VITESSE_DEPLACEMENT * dureeIteration.asSeconds();
        if (moveright) movement.x += VITESSE_DEPLACEMENT * dureeIteration.asSeconds();
        if (moveup) movement.y -= VITESSE_DEPLACEMENT * dureeIteration.asSeconds();
        if (movedown) movement.y += VITESSE_DEPLACEMENT * dureeIteration.asSeconds();

        // Collision
        sf::FloatRect nextBounds = cercle_courant->getGlobalBounds();
        nextBounds.position.x += movement.x;
        nextBounds.position.y += movement.y;

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
            cercle_courant->move(movement);
        }

        // Mise à jour de la vue
        sf::Vector2f centreVue = cercle_courant->getPosition() + sf::Vector2f(cercle_courant->getRadius(), cercle_courant->getRadius());
        sf::Vector2f mapSize = map.getMapSize();

        if (centreVue.x < 200.f) centreVue.x = 200.f;
        if (centreVue.x > mapSize.x - 200.f) centreVue.x = mapSize.x - 200.f;
        if (centreVue.y < 150.f) centreVue.y = 150.f;
        if (centreVue.y > mapSize.y - 150.f) centreVue.y = mapSize.y - 150.f;

        vue.setCenter(centreVue);
        window.setView(vue);

        window.clear();
        map.draw(window);

        for (auto& cercle : mes_cercles)
        {
            window.draw(*cercle);
        }

        window.display();
    }

    for (auto& cercle : mes_cercles)
    {
        delete cercle;
    }

    return 0;
}
