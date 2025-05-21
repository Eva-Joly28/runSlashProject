#include <SFML/Graphics.hpp>
#include <vector>
#include "Joueur.h"





//void switchPressedKey(bool isPressed, const sf::Event::KeyPressed key) {
//    switch (key.scancode)
//    {
//    case sf::Keyboard::Scancode::Left:
//        moveleft = isPressed;
//        break;
//    case sf::Keyboard::Scancode::Right:
//        moveright = isPressed;
//        break;
//    case sf::Keyboard::Scancode::Up:
//        moveup = isPressed;
//        break;
//    case sf::Keyboard::Scancode::Down:
//        movedown = isPressed;
//        break;
//    }
//}
    
int main()
{
    bool moveleft = false, moveright = false, moveup = false, movedown = false;

    auto window = sf::RenderWindow(sf::VideoMode({700, 600}), "Run & Slash");
    window.setFramerateLimit(60);

    const sf::Vector2f mapSize(2000.f, 1000.f);

 
    sf::Texture textureFond;
    if (!textureFond.loadFromFile("assets//map.jpg")) {
        return -1;
    }
    sf::Sprite spriteFond(textureFond);
    spriteFond.setScale({ 2.5f,1.8f });

	Joueur player1;
	sf::Sprite* spritePlayer1 = player1.getSprite();
    sf::Vector2u tailleTexture = spritePlayer1->getTexture().getSize();
    float scaleX = 100.f / tailleTexture.x;
    float scaleY = 150.f / tailleTexture.y;
    spritePlayer1->setScale({ scaleX, scaleY });
	spritePlayer1->setPosition({ 200.f, 150.f });
	
	sf::Clock clock;
	sf::Time deltaTime = sf::Time::Zero;
    sf::View vue(sf::FloatRect({ 0.f, 0.f }, { 400.f, 300.f }));

    while (window.isOpen())
    {
		deltaTime = clock.restart();

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                switch (keyPressed->scancode)
                {
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
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyReleased>())
            {
                switch (keyPressed->scancode)
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
        if (moveleft) {
            spritePlayer1->setRotation(sf::degrees(180));
            direction.x -= (100.f * deltaTime.asSeconds());
        }
        if (moveright) {
            spritePlayer1->setRotation(sf::degrees(-180));
            direction.x += 100.f * deltaTime.asSeconds();

        }
        if (moveup) { 
            spritePlayer1->setRotation(sf::degrees(90));
            direction.y -= 100.f * deltaTime.asSeconds(); 
        }
        if (movedown) {
            spritePlayer1->setRotation(sf::degrees(-90));
            direction.y += 100.f * deltaTime.asSeconds(); 
        }

		player1.update(direction);

        sf::Vector2f centreVue = spritePlayer1->getPosition() + spritePlayer1->getScale();
		vue.setCenter(centreVue);

        if (centreVue.x < 200.f) centreVue.x = 200.f;
        if (centreVue.x > mapSize.x - 200.f) centreVue.x = mapSize.x - 200.f;
        if (centreVue.y < 150.f) centreVue.y = 150.f;
        if (centreVue.y > mapSize.y - 150.f) centreVue.y = mapSize.y - 150.f;

        vue.setCenter(centreVue);
        
        window.clear();
		window.setView(vue);

		window.draw(spriteFond);
        window.draw(*spritePlayer1);

        window.display();
    }
}
