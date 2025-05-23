#include "Game.h"

Game::Game() : window(sf::VideoMode({ 900, 700 }), "Run & Slash"),
view(sf::FloatRect({ 0.f, 0.f }, { 400.f, 300.f })),
player(), deltaTime(sf::Time::Zero)
{
	window.setFramerateLimit(60);
	view.setCenter(player.getSprite()->getPosition());
	pathBarreVie = "assets//full_vie.png";
	textureBarreVie.loadFromFile(pathBarreVie);
	spriteBarreVie = new sf::Sprite(textureBarreVie);
	spriteBarreVie->setScale({ 3.0f, 3.0f });
	spriteBarreVie->setPosition({ 670.f, 35.f });

	// Kamikaze
	auto kamikaze = std::make_unique<Kamikaze>();
	kamikaze->getSprite()->rotate(sf::degrees(180));
	kamikaze->getSprite()->setScale({ 0.6f, 0.6f });
	kamikaze->getSprite()->setPosition({ 100.f, 300.f });
	ennemis.push_back(std::move(kamikaze));

	// Epeiste
	auto epeiste = std::make_unique<Epeiste>();
	epeiste->getSprite()->setScale({ 0.9f, 0.9f });
	epeiste->getSprite()->setPosition({ 100.f, 200.f });
	ennemis.push_back(std::move(epeiste));

	// Boss
	auto boss = std::make_unique<Boss>();
	boss->getSprite()->setPosition({ 800.f, 400.f });
	ennemis.push_back(std::move(boss));

}

void Game::run()
{
	while (window.isOpen())
	{
		deltaTime = clock.restart();
		handleEvents();
		
	}
}

void Game::handleEvents()
{
	//sf::Event event;
	while (std::optional event = window.pollEvent())
	{
		player.handleInput(&event, &window);
	}
	update(deltaTime);
	render();
}

void Game::update(sf::Time deltaTime)
{
	sf::Vector2f centre = player.getSprite()->getPosition();
	player.updateMovement(deltaTime, map.getMurs());
	centre.x = std::clamp(centre.x, 200.f, map.getMapSize().x - 200.f);
	centre.y = std::clamp(centre.y, 150.f, map.getMapSize().y - 150.f);
	view.setCenter(centre);
	for (auto& ennemi : ennemis) {
		if (player.isAlive()) {
			if (ennemi->gethitboxBounds().findIntersection(player.gethitboxBounds())) {
				ennemi->attack(&player);
			}
			else {
				ennemi->updateJoueur(&player);
				if (auto kamikaze = dynamic_cast<Kamikaze*>(ennemi.get())) {
					kamikaze->update(player.getPosition(), deltaTime.asSeconds(), &window);
				}
			}
			
		}
		
	}
	pathBarreVie = player.updatePv();
}

void Game::render()
{
	window.setView(view);
	window.clear();

	window.draw(*map.getSprite());
	window.draw(*player.getSprite());
	for (auto& ennemi : ennemis) {
		window.draw(*ennemi->getSprite());
	}

	window.setView(window.getDefaultView());
	window.draw(*spriteBarreVie);
	window.display();
}
