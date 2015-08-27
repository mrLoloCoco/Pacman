#include <SFML/Graphics.hpp>

class Enemy{
private:
	double spd; //
	char id; //

	sf::Sprite sprite; //

	char state; //mode ((f)ollow, (r)un, (o)rigin, (s)cared)
	char direction; 
	int retreat; //

	int counter; //

	int goToSquare; //
	int currentSquare; //

public:
	Enemy(char pick, double x, double y, sf::Sprite sprites);
	Enemy();

	void createGhost(char pick, double x, double y, sf::Sprite sprites); 
	void setState(char updateState); 
	
	char getState(); 

	void create(); //
	sf::Sprite FSprite(); //

	char getDirection(); //
	char getId(); 

	void forward(char dir); //
	void back(); //
	void updateGhost(); //

	int squareX(); 
	int squareY(); 

	void sSquare(int square); 
	int  ggoToSquare();
};