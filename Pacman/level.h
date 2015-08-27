#include <SFML/Graphics.hpp>

class Level
{
private:
	int num;
	char option;
	sf::Sprite sprite;
	
	bool hollow;

	double xLoc;
	double yLoc;

public:
	void create(char field, sf::Sprite sprites);
	void create(char field);

	sf::Sprite spriteFind();

	Level();

	void reset();

	int takeLeve();
	bool system();
	void id(double x, double y, int point);
	int ID();

	Level(double x, double y, bool frd, char ak, int point, sf::Sprite sprites);

	bool movement();
};
