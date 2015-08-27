#pragma once

#include "game_state.h"
#include "entity_manager.h"

class main_game : public tiny_state
{
public:
	main_game();
	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);
private:
	sf::Font font;
	sf::Text score, lives;
	EntityManager* manager;
};