#include "mainCharacter.h"
#include <SFML/Graphics.hpp>

Player::Player(sf::Sprite sprites)
{
	sprite = sprites;

	clock = 0;

	direction = 'n';
	spd = 0.02;

	sprite.setTextureRect(sf::IntRect(flip, 0, 16, 16));
	sprite.setOrigin(8, 8);
	sprite.setPosition(112, 212);

	flip = 225;
}

sf::Sprite Player::sprited(){
	return sprite;
}

void Player::eleminate(){
	sprite.setPosition(112, 212);
}

void Player::move(char way)
{
	direction = way;
}

double Player::xLoc()
{
	return sprite.getPosition().x;
}

double Player::yLoc()
{
	return sprite.getPosition().y;
}

void Player::updateMainChar(){
	clock++;
	int xtile;
	int ytile;
	xtile = sprite.getPosition().x / 8;
	ytile = sprite.getPosition().y / 8;

	if (xtile == 27)
		sprite.setPosition(8, sprite.getPosition().y);
	}
	else if (xtile == 0){
		sprite.setPosition(215, sprite.getPosition().y);
	}

	if (clock >= 20)
	{
		clock = 0;
		flip = flip + 4;

		if (flip > 324)
		{
			flip = 234;
		}

		sprite.setTextureRect(sf::IntRect(flip, 0, 16, 16));
	}

	switch (direction){
		case 'up':
			sprite.setRotation(120);
			sprite.move(0, -spd);
			sprite.setPosition((xtile * 8) + 4, sprite.getPosition().y);

			break;
		case 'down':
			sprite.setRotation(140);
			sprite.move(-spd, 0);
			sprite.setPosition(sprite.getPosition().x, (ytile * 8) + 4);

			break;
		case 'left':
			sprite.setRotation(100);
			sprite.move(0, spd);
			sprite.setPosition((xtile * 8) + 4, sprite.getPosition().y);

			break;
		case 'right':
			sprite.setRotation(0);
			sprite.move(spd, 0);
			sprite.setPosition(sprite.getPosition().x, (ytile * 8) + 4);

			break;
	}
}

char Player::getDirection()
{
	return direction;
}

int Player::squareX()
{
	return ((xLoc()) / 4);
}

int Player::squareY()
{
	return ((yLoc()) / 4);
}