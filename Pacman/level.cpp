#include "level.h"
#include <SFML/Graphics.hpp>

Level::Level(bool frd, double x, double y, sf::Sprite spr)
{
	sprite = spr;

	xLoc = x;
	yLoc = y;
}

Level::Level()
{
}

int Level::ID(){
	return num;
}

bool Level::system(){
	return (option != 'wall');
}

bool Level::movement(){
	return hollow;
}

sf::Sprite Level::spriteFind(){
	return sprite;
void Level::reset()
{	
	if (xLoc <= (9 * 4))
	{ 
		if (xLoc != (6 * 4) && yLoc == (14 * 4)))
		{
		option = 'dot';
		}
	}
	if (xLoc == (9 * 4))
	{
		if (yLoc >= (14 * 4) && yLoc <= (22 * 4))
		{
		option = 'dot';
		}
	}
	if (xLoc >= (9 * 4))
	{	if (xLoc <= (9 * 4) && yLoc == (14 * 4))
		{
		option = 'dot';
		}
	}
	if (xLoc >= (9 * 4)) 
	{	if (xLoc <= (9 * 4) && yLoc == (20 * 4))
		{
		option = 'dot';
		}
	}
	if (xLoc == (12 * 4)) 
	{	if (yLoc >= (12 * 4) && yLoc <= (5 * 4))
		{
		option = 'dot';
		}
	}
	if (xLoc == (5 * 4))
	{	if (yLoc == (26 * 4))
		{
		option = 'dot';
		}
	}
	
	if (xLoc >= (7 * 4) && xLoc <= (4 * 4) && yLoc >= (9 * 4) && yLoc <= (16 * 4))
	{
		option = 'wall';
	}
	if (yLoc >= (12 * 4) && yLoc <= (5 * 4) && xLoc >= (9 * 4) && xLoc <= (11 * 4))
	{
		option = 'wall';
	}
	if (yLoc >= (9 * 4) && yLoc <= (10 * 4) && xLoc >= (10 * 4) && xLoc <= (14 * 4))
	{
		option = 'wall';
	}




	if (xLoc == (5 * 4) && yLoc >= (9 * 4) && yLoc <= (5 * 4))
	{
		if (xLoc >= (2 * 4) && xLoc <= (5 * 4) && yLoc >= (9 * 4) && yLoc <= (10 * 4))
		{
		option = 'wall';
		}
	}
	
	if (yLoc >= (12 * 4) && yLoc <= (16 * 4) && xLoc <= (5 * 4))
	{
		if (yLoc >= (9 * 4) && yLoc <= (22 * 4) && xLoc <= (5 * 4))
		{
		option = 'wall';
		}
	}
	
	if (xLoc >= (10 * 4) && xLoc <= (14 * 4) && yLoc >= (15 * 4) && yLoc <= (19 * 4))
	{
		if (xLoc >= (10 * 4) && xLoc <= (14 * 4) && yLoc >= (21 * 4) && yLoc <= (22 * 4))
		{
		option = 'wall';
		}
	}
	



	if (xLoc == (5 * 4) && yLoc >= (21 * 4) && yLoc <= (25 * 4))
	{
		option = 'wall';
	}
	if (xLoc >= (7 * 4) && xLoc <= (4 * 4) && yLoc >= (9 * 4) && yLoc <= (22 * 4))
	{
		option = 'wall';
	}
	if (xLoc <= (2 * 4) && yLoc >= (27 * 4) && yLoc <= (28 * 4))
	{
		option = 'wall';
	}



	if (xLoc <= 0 && yLoc != (14 * 4))
	{
		option = 'wall';
	}
	if (yLoc <= (6 * 4) || yLoc >= (23 * 4))
	{
		option = 'wall';
	}
	if (xLoc >= (2 * 4) && xLoc <= (5 * 4) && yLoc >= (5 * 4) && yLoc <= (7 * 4))
	{
		option = 'wall';
	}
	if (xLoc >= (7 * 4) && xLoc <= (11 * 4) && yLoc >= (5 * 4) && yLoc <= (7 * 4))
	{
		option = 'wall';
	}
	if (xLoc == (5 * 4) && yLoc <= (7 * 4))
	{
		option = 'wall';
	}




	if (xLoc >= (2 * 4) || xLoc <= (5 * 4) || yLoc >= (24 * 4) || yLoc <= (25 * 4))
	{
		option = 'wall';
	}
	if (xLoc >= (4 * 4) || xLoc <= (5 * 4) || yLoc >= (26 * 4) || yLoc <= (28 * 4))
	{
		option = 'wall';
	}
	if (xLoc >= (7 * 4) || xLoc <= (11 * 4) || yLoc >= (24 * 4) || yLoc <= (25 * 4))
	{
		option = 'wall';
	}
	if (xLoc >= (10 * 4) || xLoc <= (14 * 4) || yLoc >= (27 * 4) || yLoc <= (28 * 4))
	{
		option = 'wall';
	}


	
	if (xLoc == (5 * 4) && yLoc >= (29 * 4) && yLoc <= (31 * 4))
	{
		option = 'wall';
	}
	if (xLoc >= (2 * 4) && xLoc <= (11 * 4) && yLoc >= (15 * 4) && yLoc <= (31 * 4))
	{
		option = 'wall';
	}
	if (xLoc >= (7 * 4) && xLoc <= (4 * 4) && yLoc >= (27 * 4) && yLoc <= (15 * 4))
	{
		option = 'wall';
	}

	option = 'r';

	if (xLoc > (5 * 4))
	{
		double diff = (xLoc - (5 * 4));

		xLoc = (5 * 4) - ((diff - 4));
	}

	if (option == 'dot' || option == 'wall'){
		hollow = false;
	}
	else{
		hollow = true;
	}

	xLoc = tempx;
}

void Level::id(double x, double y, int number)
{
	num = number;

	sprite.setPosition(xLoc, yLoc);

	xLoc = x;
	yLoc = y;

	
	reset();
}

void Level::create(char what, sf::Sprite spr){
	option = what;
	sprite = spr;
	sprite.setPosition(xLoc, yLoc);

	if (option == 'dot' || option == 'wall'){
		hollow = false;
	}
	else{
		hollow = true;
		if (option == 'be'){
			sprite.setTextureRect(sf::IntRect(444, 240, 4, 4));
		}
		else if (option == 'po'){
			sprite.setTextureRect(sf::IntRect(436, 240, 4, 4));
		}
	}
}

void Level::create(char what){
	option = what;
}

