#include <SFML/Graphics.hpp>
#include <vector>

#define VITESSE_DEPLACEMENT 120

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 700, 600 }), "Run & Slash !");
    window.setFramerateLimit(60);

    // Taille de la carte plus grande que la fenêtre
    const sf::Vector2f mapSize(2000.f, 1000.f);

    // Rétrécir la boule
    sf::CircleShape* cercle_courant = new sf::CircleShape(25.f); // Réduit la taille à 25
    cercle_courant->setFillColor(sf::Color::Green);
    cercle_courant->setPosition({ 200.f, 150.f }); // Position initiale

    std::vector<sf::Drawable*> mes_cercles;
    mes_cercles.push_back(cercle_courant);

    // Créer des murs
    std::vector<sf::RectangleShape> murs;
    sf::RectangleShape mur1(sf::Vector2f(10.f, mapSize.y)); // Mur gauche
    mur1.setFillColor(sf::Color::White);
    mur1.setPosition({ 0.f, 0.f });
    murs.push_back(mur1);

    sf::RectangleShape mur2(sf::Vector2f(10.f, mapSize.y)); // Mur droit
    mur2.setFillColor(sf::Color::White);
    mur2.setPosition({ mapSize.x - 10.f, 0.f });
    murs.push_back(mur2);

    sf::RectangleShape mur3(sf::Vector2f(mapSize.x, 10.f)); // Mur supérieur
    mur3.setFillColor(sf::Color::White);
    mur3.setPosition({ 0.f, 0.f });
    murs.push_back(mur3);

    sf::RectangleShape mur4(sf::Vector2f(mapSize.x, 10.f)); // Mur inférieur
    mur4.setFillColor(sf::Color::White);
    mur4.setPosition({ 0.f, mapSize.y - 10.f });
    murs.push_back(mur4);

    bool moveleft = false, moveright = false, moveup = false, movedown = false;

    sf::Clock clock;
    sf::Time dureeIteration = sf::Time::Zero;

    // Créer une vue qui sera déplacée suivant la boule
    sf::View vue(sf::FloatRect({ 0.f, 0.f }, { 400.f, 300.f }));

    while (window.isOpen())
    {
        dureeIteration = clock.restart();

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
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
                    cercle_courant = new sf::CircleShape(25.f); // Réduit la taille à 25
                    cercle_courant->setFillColor(sf::Color::Red);
                    cercle_courant->setPosition({ 200.f, 150.f }); // Position initiale
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

        // Calculer le nouveau mouvement
        sf::Vector2f movement(0.f, 0.f);
        if (moveleft) movement.x -= VITESSE_DEPLACEMENT * dureeIteration.asSeconds();
        if (moveright) movement.x += VITESSE_DEPLACEMENT * dureeIteration.asSeconds();
        if (moveup) movement.y -= VITESSE_DEPLACEMENT * dureeIteration.asSeconds();
        if (movedown) movement.y += VITESSE_DEPLACEMENT * dureeIteration.asSeconds();

        // Vérifier les collisions avec les murs
        sf::FloatRect cercleBounds = cercle_courant->getGlobalBounds();
        cercleBounds.position.x += movement.x;
        cercleBounds.position.y += movement.y;

        bool collision = false;

        for (const auto& mur : murs)
        {
            if (cercleBounds.findIntersection(mur.getGlobalBounds())) // Utiliser findIntersection
            {
                collision = true;
                break;
            }
        }

        // Appliquer le mouvement si pas de collision
        if (!collision)
        {
            cercle_courant->move(movement);
        }

        // Mettre à jour la vue pour suivre la boule
        sf::Vector2f centreVue = cercle_courant->getPosition() + sf::Vector2f(cercle_courant->getRadius(), cercle_courant->getRadius());
        vue.setCenter(centreVue);

        // Limiter la vue dans les bornes de la carte
        if (centreVue.x < 200.f) centreVue.x = 200.f;
        if (centreVue.x > mapSize.x - 200.f) centreVue.x = mapSize.x - 200.f;
        if (centreVue.y < 150.f) centreVue.y = 150.f;
        if (centreVue.y > mapSize.y - 150.f) centreVue.y = mapSize.y - 150.f;

        vue.setCenter(centreVue);

        window.clear();
        window.setView(vue); // Appliquer la vue

        for (const auto& mur : murs)
        {
            window.draw(mur);
        }
        for (int i = 0; i < mes_cercles.size(); ++i)
        {
            window.draw(*mes_cercles[i]);
        }
        window.display();
    }

    for (int i = 0; i < mes_cercles.size(); ++i)
    {
        delete mes_cercles[i];
    }
}
