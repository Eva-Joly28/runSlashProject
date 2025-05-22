#include <SFML/Graphics.hpp>
#include <vector>
#include "Joueur.h"
#include "map.h"

#define VITESSE_DEPLACEMENT 120

int main()
{
    // Création de la fenêtre
    sf::RenderWindow window(sf::VideoMode({ 700, 600 }), "Run & Slash");
    window.setFramerateLimit(60);

    // Chargement de la carte
    Map map;

    // Création du joueur
    Joueur player1;
    sf::Sprite* spritePlayer1 = player1.getSprite();
    spritePlayer1->setScale({ 50.0f, 70.0f });  // Mise à l'échelle du sprite
    spritePlayer1->setPosition({ 200.f, 150.f });  // Position initiale

    // Variables de déplacement
    bool moveLeft = false, moveRight = false, moveUp = false, moveDown = false;

    // Horloge pour le deltaTime
    sf::Clock clock;
    sf::Time deltaTime = sf::Time::Zero;

    // Vue initiale
    sf::View vue(sf::FloatRect({ 0.f, 0.f }, { 400.f, 300.f }));

    // Boucle principale
    while (window.isOpen())
    {
        deltaTime = clock.restart();

        // Gestion des événements
        while (const std::optional<sf::Event> event = window.pollEvent())
        {
            if (event->type == sf::Event::Closed)
                window.close();
            else if (event->type == sf::Event::KeyPressed)
            {
                switch (event->key.scancode)
                {
                case sf::Keyboard::Scancode::Escape:
                    window.close();
                    break;
                case sf::Keyboard::Scancode::Left:
                    moveLeft = true;
                    break;
                case sf::Keyboard::Scancode::Right:
                    moveRight = true;
                    break;
                case sf::Keyboard::Scancode::Up:
                    moveUp = true;
                    break;
                case sf::Keyboard::Scancode::Down:
                    moveDown = true;
                    break;
                default:
                    break;
                }
            }
            else if (event->type == sf::Event::KeyRelease)
            {
                switch (event->key.scancode)
                {
                case sf::Keyboard::Scancode::Left:
                    moveLeft = false;
                    break;
                case sf::Keyboard::Scancode::Right:
                    moveRight = false;
                    break;
                case sf::Keyboard::Scancode::Up:
                    moveUp = false;
                    break;
                case sf::Keyboard::Scancode::Down:
                    moveDown = false;
                    break;
                default:
                    break;
                }
            }
        }

        // Calcul de la direction de déplacement
        sf::Vector2f direction(0.f, 0.f);
        if (moveLeft) direction.x -= VITESSE_DEPLACEMENT * deltaTime.asSeconds();
        if (moveRight) direction.x += VITESSE_DEPLACEMENT * deltaTime.asSeconds();
        if (moveUp) direction.y -= VITESSE_DEPLACEMENT * deltaTime.asSeconds();
        if (moveDown) direction.y += VITESSE_DEPLACEMENT * deltaTime.asSeconds();

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
            player1.update(direction);
        }

        // Mise à jour de la vue pour suivre le joueur
        sf::Vector2f centreVue = spritePlayer1->getPosition() + spritePlayer1->getScale();
        sf::Vector2f mapSize = map.getMapSize();

        if (centreVue.x < 200.f) centreVue.x = 200.f;
        if (centreVue.x > mapSize.x - 200.f) centreVue.x = mapSize.x - 200.f;
        if (centreVue.y < 150.f) centreVue.y = 150.f;
        if (centreVue.y > mapSize.y - 150.f) centreVue.y = mapSize.y - 150.f;

        vue.setCenter(centreVue);
        window.setView(vue);

        // Affichage
        window.clear();
        map.draw(window);
        window.draw(*spritePlayer1);
        window.display();
    }

    return 0;
}
