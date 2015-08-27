#include <SFML/Graphics.hpp>

class mainCharacter{
private:
	sf::Sprite sprite;
	bool destroyed;

	float spd;
	char direction;

	int clock;
	int flip;
	
public:
	Player(sf::Sprite sprites);

	sf::Sprite sprited();
	char getDirection();

	void move(char way);
	void updateMainChar();

	int shovelForward();
	void wrapU();
	int shovelBackward();
	void wrapD();

	double xLoc();
	double yLoc();

	int squareX();
	int squareY();

	void eleminate();
};
