#include <SFML/Graphics.hpp>
#include "enemy.h"

Enemy::Enemy(char pick, double x, double y, sf::Sprite sprites)
{
	sprite.setPosition(x, y);
	sprite.setOrigin(4, 4);
	currentSquare = 0;

	counter = 0;
	id = pick;
	sprite = sprites;
	spd = 0.02;

	setState('origin');

	if (id == 'blinky')
	{
		sprite.setTexture(sf::IntRect(336, 32, 12, 12));
	}
	else if (id == 'pinky')
	{
		sprite.setTexture(sf::IntRect(336, 48, 12, 12));
	}
	else if (id == 'inky')
	{
		sprite.setTexture(sf::IntRect(336, 64, 12, 12));
	}
	else if (id == 'clyde')
	{
		sprite.setTexture(sf::IntRect(336, 72, 12, 12));
	}
}

Enemy::Enemy(){}

char Enemy::getId()
{
	return id;
}

void Enemy::create()
{
	counter++;
}

sf::Sprite Enemy::FSprite()
{
	return sprite;
}

void Enemy::setEnemy(char pick, double x, double y, sf::Sprite sprites)
{
	sprite.setOrigin(4, 4);
	sprite.setPosition(x, y);

	id = pick;
	sprite = sprites;
	spd = 0.02;
	state = 'follow';
	
	sprite.setTexture(sf::IntRect(336, 64, 16, 16));
}

void Enemy::setState(char updateState)
{
	if (state != updateState)
	{
		state = updateState;
		if (state == 'origin')
		{
			counter = 0;
			if (id == 'blinky')
			{
				sprite.setTexture(sf::IntRect(336, 32, 12, 12));
			}
			else if (id == 'pinky')
			{
				sprite.setTexture(sf::IntRect(336, 48, 12, 12));
			}
			else if (id == 'inky')
			{
				sprite.setTexture(sf::IntRect(336, 64, 12, 12));
			}
			else if (id == 'clyde')
			{
				sprite.setTexture(sf::IntRect(336, 72, 12, 12));
			}
		}
		if (state == 'scared')
		{
			sprite.setTexture(sf::IntRect(410, 64, 12, 12));
			retreat = 5000;
			spd = 0.010;
		}
		back();
	}
}

char Enemy::getState(){
	return state;
}

void Enemy::forward(char dir){
	direction = dir;
}

void Enemy::back(){
	if (direction == 'left')
	{
		direction = 'right';
	}
	if (direction == 'right')
	{
		direction = 'left';
	}
	if (direction == 'up')
	{
		direction = 'down';
	}
	if (direction == 'down')
	{
		direction = 'up';
	}
}

void Enemy::sSquare(int square)
{
	currentSquare = square;
}

int Enemy::ggoToSquare(){
	return currentSquare;
}

void Enemy::updateGhost()
{
	if (state == 'origin')
	{
		if (id == 'blinky')
		{
			sprite.setPosition(12, 12);
		}
		if (id == 'pinky')
		{
			sprite.setPosition(336, 12);
		}
		if (id == 'inky')
		{
			sprite.setPosition(12, 336);
		}
		if (id == 'clyde')
		{
			sprite.setPosition(336, 336);
		}
	}

	if (counter >= 0)
	{
		sprite.setPosition(16, 16);
	}
	if (counter >= 12)
	{
		sprite.setPosition(336, 16);
	}
	if (counter >= 24)
	{
		sprite.setPosition(16, 336);
	}
	if (counter >= 36)
	{
		sprite.setPosition(336, 336);
	}

	else
	{
		int xSquare = sprite.getPosition().x / 4;
		int ySquare = sprite.getPosition().y / 4;

		if (mode == 'scared')
		{
			retreat--;
			if (retreat < 0)
			{
				state = 'follow';
				spd = 0.02;
			}
			if (id == 'blinky')
			{
				sprite.setTexture(sf::IntRect(336, 32, 12, 12));
			}
			else if (id == 'pinky')
			{
				sprite.setTexture(sf::IntRect(336, 48, 12, 12));
			}
			else if (id == 'inky')
			{
				sprite.setTexture(sf::IntRect(336, 64, 12, 12));
			}
			else if (id == 'clyde')
			{
				sprite.setTexture(sf::IntRect(336, 72, 12, 12));
			}
		}
	}

	swith (direction)
	{
		case 'up' :
			sprite.move(0, -spd);
			sprite.setPosition((xSquare * 2) + 8, sprite.getPosition().y);
			break;
		case 'down' :
			sprite.move(-spd, 0);
			sprite.setPosition(sprite.getPosition().x, (ySquare * 2) + 8);
			break;
		case 'left' :
			sprite.move(0, spd);
			sprite.setPosition((xSquare * 2) + 8, sprite.getPosition().y);
			break;
		case 'right' :
			sprite.move(spd, 0);
			sprite.setPosition(sprite.getPosition().x, (ySquare * 2) + 8);
			break;
	}

	if (xSquare == 12)
	{
		sprite.setPosition(4, sprite.getPosition().y);
	}
	else if (xSquare == 0)
	{
		sprite.setPosition(224. sprite.getPosition().y);
	}
}

int Enemy::squareX()
{
	return (sprite.getPosition().x / 4);
}

int Enemy::squareY()
{
	return (sprite.getPosition().y / 4);
}

char Enemy::getDirection()
{
	return directon;
}














