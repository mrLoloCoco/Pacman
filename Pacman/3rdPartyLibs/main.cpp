#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "tile.h"
#include "player.h"
#include "ghosts.h"
#include <cstdlib>
#include <cmath>
#include <ctime>


int main(){

	Level levelMap[36][28];

	sf::RenderWindow window(sf::VideoMode(screenW, screenH), "SFML Application");
	sf::Texture spriteSheet;
	spriteSheet.loadFromFile("spriteSheet.png");

	int screenW = 488;
	int screenH = 512;

	int map_rows = 36;
	int map_cols = 28;

	sf::Sprite playerSprite;
	playerSprite.setTexture(spriteSheet);
	playerSprite.setTextureRect(sf::IntRect(470, 0, 16, 16));
	playerSprite.setOrigin(sf::Vector2f(8, 8));
	playerSprite.setPosition(14 * 8, 20 * 8); //(screenW/2,screenH/2+20); //just under ghost house
	Player player(20, 14, playerSprite);
	sf::Sprite background;
	sf::Texture mazeBackground;
	background.setPosition(10, 12);

	
	

	for (int i = 0; i < map_rows; i++)
	{
		for (int j = 0; j < map_cols; j++)
		{
			levelMap[i][j].resetMap(i, j);
			if (levelMap[i][j].getType() == 'd')
			{
				levelMap[i][j].setSprite(dot);
			}
			if (levelMap[i][j].getType() == 'u')
			{
				levelMap[i][j].setSprite(powerup);
			}
			if (levelMap[i][j].getType() == 'e')
			{
				levelMap[i][j].setSprite(wall);
			}

		}
	}

	sf::Font font;

	sf::Text scoreDisplay;
	scoreDisplay.setFont(font);
	scoreDisplay.setCharacterSize(11);
	scoreDisplay.setPosition(8, screenH - 16);
	scoreDisplay.setColor(sf::Color::White);
	int score = 0;
	scoreDisplay.setString("Score: "+ (std::to_string(score)) );

//ghosts	
	//ghost sprites
	sf::Texture ghostTex;
	ghostTex.loadFromFile("Pac Man Map.png");

	//blinky
	sf::Sprite blinkySpr;
	blinkySpr.setTexture(ghostTex);
	sf::IntRect blink (228, 64, 16, 16);
	blinkySpr.setTextureRect(blink);
	blinkySpr.setOrigin(8, 8);
	
	Ghosts blinky('c', 'b', blinkySpr, 14, 14);
	blinkySpr.setPosition(14 * 8, 14 * 8); 

	//inky
	sf::Sprite inkySpr;
	inkySpr.setTexture(ghostTex);
	inkySpr.setTextureRect(sf::IntRect(228, 96, 16, 16));
	inkySpr.setOrigin(8, 8);

	Ghosts inky('h', 'i', inkySpr, 14, 14); //movement will start outside house
	inkySpr.setPosition(11.5 * 8, 16.5* 8);

	//pinky
	sf::Sprite pinkySpr;
	pinkySpr.setTexture(ghostTex);
	pinkySpr.setTextureRect(sf::IntRect(228, 80, 16, 16));
	pinkySpr.setOrigin(8, 8);

	Ghosts pinky('h', 'p', pinkySpr, 14, 14);
	pinkySpr.setPosition(13.5 * 8, 17 * 8);

	//clyde
	sf::Sprite clydeSpr;
	clydeSpr.setTexture(ghostTex);
	clydeSpr.setTextureRect(sf::IntRect(228, 112, 16, 16));
	clydeSpr.setOrigin(8, 8);

	Ghosts clyde('h', 'c', clydeSpr, 14, 14);
	clydeSpr.setPosition(15.5 * 8, 16.5 * 8);

	//fright sprite
	//sf::Sprite frightSpr;
	//frightSpr.setTexture(ghostTex);
	sf::IntRect fright (356, 64, 16, 16);
	//frightSpr.setTextureRect(fright);
	//frightSpr.setOrigin(8, 8);

	//timer
	sf::Clock clock;
	sf::Time elapsed1;
	int waveCount = 1;
	int dotCounter = 0;
	
	////////--------window loop--------------/////////////
	while (window.isOpen()){

		
		elapsed1 = clock.getElapsedTime();
		if (clock.getElapsedTime() >= sf::seconds(4)){
			/*
			blinky.frightenGhost(fright);
			blinkySpr.setTextureRect(fright); //fright blinky
			inky.frightenGhost(fright);
			inkySpr.setTextureRect(fright); //fright inky
			pinky.frightenGhost(fright);
			pinkySpr.setTextureRect(fright); //fright pinky
			clyde.frightenGhost(fright);
			clydeSpr.setTextureRect(fright); //fright clyde
			*/
		}
		
			
		int pRow = player.xpos;
		int pCol = player.ypos;
		char toTileType;

		sf::Event event;
		while (window.pollEvent(event)){

			if (event.type == sf::Event::Closed){
				window.close();
			}

// can't get continuous movement to work to save my life

			//move player up
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
				toTileType = levelMap[pRow - 1][pCol].getType();
				if (toTileType != 'w'){
					player.setDirection('u');
					player.move();
					//playerSprite = player.getSprite();
				}
				//adjust score & tile if applicable
				if (toTileType == 'd'){
					levelMap[pRow - 1][pCol].setType('e');
					score += 1;
					scoreDisplay.setString("Score: " + (std::to_string(score)));
				}
				else if (toTileType == 'u'){
					levelMap[pRow - 1][pCol].setType('e');
					score += 2;
					scoreDisplay.setString("Score: " + (std::to_string(score)));
					blinky.frightenGhost(fright);
					blinkySpr.setTextureRect(fright); //fright blinky
					inky.frightenGhost(fright);
					inkySpr.setTextureRect(fright); //fright inky
					pinky.frightenGhost(fright);
					pinkySpr.setTextureRect(fright); //fright pinky
					clyde.frightenGhost(fright);
					clydeSpr.setTextureRect(fright); //fright clyde
				}
			}
			//move player down
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
				toTileType = levelMap[pRow + 1][pCol].getType();
				if (toTileType != 'w'){
					player.setDirection('d');
					player.move();
					//playerSprite = player.getSprite();
				}
				//adjust score & tile if applicable
				if (toTileType == 'd'){
					levelMap[pRow + 1][pCol].setType('e');
					score += 1;
					scoreDisplay.setString("Score: " + (std::to_string(score)));
				}
				else if (toTileType == 'u'){
					levelMap[pRow + 1][pCol].setType('e');
					score += 2;
					scoreDisplay.setString("Score: " + (std::to_string(score)));
					blinky.frightenGhost(fright);
					blinkySpr.setTextureRect(fright); //fright blinky
					inky.frightenGhost(fright);
					inkySpr.setTextureRect(fright); //fright inky
					pinky.frightenGhost(fright);
					pinkySpr.setTextureRect(fright); //fright pinky
					clyde.frightenGhost(fright);
					clydeSpr.setTextureRect(fright); //fright clyde
				}
			}
			//move player left
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
				toTileType = levelMap[pRow][pCol - 1].getType();
				if (toTileType != 'w'){
					player.setDirection('l');
					if (pRow == 17 && pCol == 1) player.wrapHorizontal();
					else {
						player.move();
					}
					//playerSprite = player.getSprite();
				}
				//adjust score & tile if applicable
				if (toTileType == 'd'){
					levelMap[pRow][pCol - 1].setType('e');
					score += 1;
					scoreDisplay.setString("Score: " + (std::to_string(score)));
				}
				else if (toTileType == 'u'){
					levelMap[pRow][pCol-1].setType('e');
					score += 2;
					scoreDisplay.setString("Score: " + (std::to_string(score)));
					blinky.frightenGhost(fright);
					blinkySpr.setTextureRect(fright); //fright blinky
					inky.frightenGhost(fright);
					inkySpr.setTextureRect(fright); //fright inky
					pinky.frightenGhost(fright);
					pinkySpr.setTextureRect(fright); //fright pinky
					clyde.frightenGhost(fright);
					clydeSpr.setTextureRect(fright); //fright clyde
				}
			}
			//move player right
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
				toTileType = levelMap[pRow][pCol + 1].getType();
				if (pRow == 17 && pCol == 27) {
					player.setDirection('r');
					player.wrapHorizontal();
					//playerSprite = player.getSprite();
				}
				else{
					if (toTileType != 'w'){
						player.setDirection('r');
						player.move();
					}
				}
				//playerSprite = player.getSprite();
				//adjust score & tile if applicable
				if (toTileType == 'd'){
					levelMap[pRow][pCol + 1].setType('e');
					score += 1;
					scoreDisplay.setString("Score: " + (std::to_string(score)));
				}
				else if (toTileType == 'u'){
					levelMap[pRow][pCol+1].setType('e');
					score += 2;
					scoreDisplay.setString("Score: " + (std::to_string(score)));
					blinky.frightenGhost(fright);
					blinkySpr.setTextureRect(fright); //fright blinky
					inky.frightenGhost(fright);
					inkySpr.setTextureRect(fright); //fright inky
					pinky.frightenGhost(fright);
					pinkySpr.setTextureRect(fright); //fright pinky
					clyde.frightenGhost(fright);
					clydeSpr.setTextureRect(fright); //fright clyde
				}
			}

			//reset dots
			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::R)){
				for (int i = 0; i < map_rows; i++){
					for (int j = 0; j < map_cols; j++){
						levelMap[i][j].resetMap(i, j);
						if (levelMap[i][j].getType() == 'd'){
							levelMap[i][j].setSprite(dot);
						}
						if (levelMap[i][j].getType() == 'u'){
							levelMap[i][j].setSprite(powerup);
						}
						if (levelMap[i][j].getType() == 'e'){
							levelMap[i][j].setSprite(wall);
						}

					}
				}
			}


			playerSprite = player.getSprite();

			window.clear();
			window.draw(background);

			//draw dots and powerups
			for (int j = 0; j < map_rows; j++){
				for (int i = 0; i < map_cols; i++){
					int xpos = i * 8;
					int ypos = j * 8;
					Level t = levelMap[j][i]; //j row, i col

					/*
					if (i == 25 && j == 26) {
						//playerSprite.setPosition(i * 8, j * 8);
						//window.draw(playerSprite);
						}
						//*/

					if (t.getType() == 'd' || t.getType() == 'u'){
						sf::Sprite drawTi = t.getSprite();
						drawTi.setPosition(xpos, ypos);
						window.draw(drawTi);

					} 
					/*
					else if (t.getType() == 'e'){
						sf::Sprite drawTi = wall; //t.getSprite();
						drawTi.setPosition(xpos, ypos);
						window.draw(drawTi);
					}
					*/
				}
			}


			window.draw(playerSprite);
			window.draw(blinkySpr);
			window.draw(inkySpr);
			window.draw(pinkySpr);
			window.draw(clydeSpr);
			window.draw(scoreDisplay);

			window.display();
		}

	}
}