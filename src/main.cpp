#include <SFML/Graphics.hpp>
#include "map.h"
#define VITESSE 120

#define VITESSE_DEPLACEMENT 120
    auto window = sf::RenderWindow(sf::VideoMode({700, 600}), "CMake SFML Project");


    Map map;
    sf::Sprite* spriteMap = map.getSprite();

    Joueur player1;
    sf::Sprite* spritePlayer1 = player1.getSprite();
    sf::Vector2u tailleTexture = spritePlayer1->getTexture().getSize();
    float scaleX = 100.f / tailleTexture.x;
    float scaleY = 150.f / tailleTexture.y;
    spritePlayer1->setScale({ scaleX, scaleY });
    spritePlayer1->setPosition({ 200.f, 150.f });

//    case sf::Keyboard::Scancode::Down:
//        movedown = isPressed;
//        break;
//    }
//}
    
    
int main()
<<<<<<<<< Temporary merge branch 1
    bool moveleft = false, moveright = false, moveup = false, movedown = false;

    auto window = sf::RenderWindow(sf::VideoMode({700, 600}), "Run & Slash");
    auto window = sf::RenderWindow(sf::VideoMode({700, 600}), "Run & Slash");
    window.setFramerateLimit(60);
    const sf::Vector2f mapSize(2000.f, 1000.f);
    const sf::Vector2f mapSize(2000.f, 1000.f);
 
    sf::Texture textureFond;
    if (!textureFond.loadFromFile("assets//map.jpg")) {
        return -1;
    }
    sf::Sprite spriteFond(textureFond);
    spriteFond.setScale({ 2.5f,1.8f });

	Joueur player1;
	sf::Sprite* spritePlayer1 = player1.getSprite();
    spritePlayer1->setScale({ 50.0f, 70.0f });
	spritePlayer1->setPosition({ 200.f, 150.f });
	
	sf::Clock clock;
	sf::Time deltaTime = sf::Time::Zero;

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
    sf::Time deltaTime = sf::Time::Zero;

    sf::View vue(sf::FloatRect({ 0.f, 0.f }, { 400.f, 300.f }));

    while (window.isOpen())
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
                case sf::Keyboard::Scancode::Up:
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
                    break;
                case sf::Keyboard::Scancode::Up:
                    moveup = false;
                    break;
                case sf::Keyboard::Scancode::Down:
                    movedown = false;
                    break;
                }
            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                switch (keyPressed->scancode)
                {
                case sf::Keyboard::Scancode::Left:
            player1->update(collision);
                    break;
        window.setView(vue);
        window.clear();
                switch (keyPressed->scancode)
                {
		window.draw(*spritePlayer1);
		
		window.display();
	}
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
        if (moveleft) { direction.x -= (100.f * deltaTime.asSeconds()); }
        if (moveright) { direction.x += 100.f * deltaTime.asSeconds();}
        if (moveup) { direction.y -= 100.f * deltaTime.asSeconds(); }
        if (movedown) { direction.y += 100.f * deltaTime.asSeconds(); }

		player1.update(direction);

        sf::Vector2f centreVue = spritePlayer1->getPosition() + spritePlayer1->getScale();
		vue.setCenter(centreVue);
=========
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
        nextBounds.position.y += movement.y;

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
            cercle_courant->move(movement);
            cercle_courant->move(movement);

        // Mise à jour de la vue
        sf::Vector2f centreVue = cercle_courant->getPosition() + sf::Vector2f(cercle_courant->getRadius(), cercle_courant->getRadius());
        sf::Vector2f mapSize = map.getMapSize();
>>>>>>>>> Temporary merge branch 2

        if (centreVue.x < 200.f) centreVue.x = 200.f;
        if (centreVue.x > mapSize.x - 200.f) centreVue.x = mapSize.x - 200.f;
        if (centreVue.y < 150.f) centreVue.y = 150.f;
        if (centreVue.y > mapSize.y - 150.f) centreVue.y = mapSize.y - 150.f;

        vue.setCenter(centreVue);
<<<<<<<<< Temporary merge branch 1
        
        window.clear();
		window.setView(vue);

		window.draw(spriteFond);
        window.draw(*spritePlayer1);
=========
        window.setView(vue);
        window.setView(vue);


        for (auto& cercle : mes_cercles)
        {
            window.draw(*cercle);
        }
>>>>>>>>> Temporary merge branch 2

        window.display();
    }
    }

    return 0;
}
