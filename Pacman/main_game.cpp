#include <stdio.h>

#include "main_menu.h"
#include "main_game.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "level.h"
#include "mainCharacter.h"
#include "enemy.h"
#include <cstdlib>
#include <cmath>
#include <ctime>



bool won = false;

        main_game::main_game()
        {
            Level levelMap[36][28];

            sf::RenderWindow window(sf::VideoMode(screenW, screenH), "Pacman Game");
            sf::Texture spriteSheet;
            spriteSheet.loadFromFile("SpriteSheet.png");

            int screenW = 488;
            int screenH = 512;

            int map_rows = 36;
            int map_cols = 28;

            sf::Sprite playerSprite;
            playerSprite.setTexture(spriteSheet);
            playerSprite.setTextureRect(sf::IntRect(470, 0, 16, 16));
            playerSprite.setOrigin(sf::Vector2f(8, 8));
            playerSprite.setPosition(14 * 8, 20 * 8); 
            Player player(20, 14, playerSprite);
            sf::Sprite background;
            sf::Texture mazeBackground;
            background.setPosition(10, 12);

    
    

            for (int a = 0; a < map_rows; a++)
            {
                for (int b = 0; b < map_cols; b++)
                {
                    levelMap[a][b].resetMap(a, b);
                    if (levelMap[a][b].getType() == 'ball')
                    {
                        levelMap[a][b].setSprite(ball);
                    }
                    if (levelMap[a][b].getType() == 'power')
                    {
                        levelMap[a][b].setSprite(wall);
                    }

                }
            }

        sf::Font font;

        sf::Clock clock;
        sf::Time elapsed1;
        int waveCount = 1;
        int dotCounter = 0;


        sf::Texture ghostTex;
        ghostTex.loadFromFile("Level1 (blue).png");

        sf::Sprite blinkySpr;
       
        blinkySpr.setOrigin(8, 8);

        blinkySpr.setTexture(ghostTex);
        sf::IntRect blink (228, 64, 16, 16);
        blinkySpr.setTextureRect(blink);
        Ghosts blinky('follow', 'blinky', blinkySpr, 14, 14);
        blinkySpr.setPosition(14 * 8, 14 * 8); 

        sf::Sprite inkySpr;

       
        inkySpr.setOrigin(8, 8);

        inkySpr.setTexture(ghostTex);
        inkySpr.setTextureRect(sf::IntRect(228, 96, 16, 16));
        Ghosts inky('origin', 'inky', inkySpr, 14, 14); 
        inkySpr.setPosition(11.5 * 8, 16.5* 8);

        sf::Sprite pinkySpr;

        pinkySpr.setOrigin(8, 8);

        pinkySpr.setTexture(ghostTex);
        pinkySpr.setTextureRect(sf::IntRect(228, 80, 16, 16));
        Ghosts pinky('origin', 'pinky', pinkySpr, 14, 14);
        pinkySpr.setPosition(13.5 * 8, 17 * 8);

        sf::Sprite clydeSpr;
        
        clydeSpr.setOrigin(8, 8);

        clydeSpr.setTexture(ghostTex);
        clydeSpr.setTextureRect(sf::IntRect(228, 112, 16, 16));
        Ghosts clyde('origin', 'clyde', clydeSpr, 14, 14);
        clydeSpr.setPosition(15.5 * 8, 16.5 * 8);

        sf::IntRect fright (356, 64, 16, 16);

        sf::Text scoreDisplay;
        scoreDisplay.setFont(font);
        scoreDisplay.setCharacterSize(11);
        scoreDisplay.setPosition(8, screenH - 16);
        scoreDisplay.setColor(sf::Color::White);
        int score = 0;
        scoreDisplay.setString("Score: "+ (std::to_string(score)) );

            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                levelEntity = levelMap[pRow - 1][pCol].getType();
                player.setDirection('up');
                player.move();
                }
                if (levelEntity == 'u')
                {
                    levelMap[pRow - 1][pCol].setType('power');
                    score += 2;
                    scoreDisplay.setString("Score: " + (std::to_string(score)));
                    blinky.frightenGhost(fright);
                    blinkySpr.setTextureRect(fright); 
                    inky.frightenGhost(fright);
                    inkySpr.setTextureRect(fright);
                    pinky.frightenGhost(fright);
                    pinkySpr.setTextureRect(fright); 
                    clyde.frightenGhost(fright);
                    clydeSpr.setTextureRect(fright); 
                }
                else if (levelEntity == 'ball')
                {
                    levelMap[pRow - 1][pCol].setType('power');
                    score += 1;
                    scoreDisplay.setString("Score: " + (std::to_string(score)));
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                levelEntity = levelMap[pRow + 1][pCol].getType();
                player.setDirection('down');
                player.move();
                }
                if (levelEntity == 'power')
                {
                    levelMap[pRow + 1][pCol].setType('power');
                    score += 2;
                    scoreDisplay.setString("Score: " + (std::to_string(score)));
                    blinky.frightenGhost(fright);
                    blinkySpr.setTextureRect(fright);
                    inky.frightenGhost(fright);
                    inkySpr.setTextureRect(fright);
                    pinky.frightenGhost(fright);
                    pinkySpr.setTextureRect(fright); 
                    clyde.frightenGhost(fright);
                    clydeSpr.setTextureRect(fright);
                }
                else if (levelEntity == 'ball')
                {
                    levelMap[pRow + 1][pCol].setType('power');
                    score += 1;
                    scoreDisplay.setString("Score: " + (std::to_string(score)));
                }
            }


            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                levelEntity = levelMap[pRow][pCol - 1].getType();
                    player.setDirection('left');
                    if (pRow == 17 && pCol == 1) player.wrapHorizontal();
                    else {
                        player.move();
                    }
                }
                if (levelEntity == 'power')
                {
                    levelMap[pRow][pCol-1].setType('power');
                    score += 2;
                    scoreDisplay.setString("Score: " + (std::to_string(score)));
                    blinky.frightenGhost(fright);
                    blinkySpr.setTextureRect(fright);
                    inky.frightenGhost(fright);
                    inkySpr.setTextureRect(fright);
                    pinky.frightenGhost(fright);
                    pinkySpr.setTextureRect(fright); 
                    clyde.frightenGhost(fright);
                    clydeSpr.setTextureRect(fright); 
                }
                else if (levelEntity == 'ball')
                {
                    levelMap[pRow][pCol - 1].setType('power');
                    score += 1;
                    scoreDisplay.setString("Score: " + (std::to_string(score)));
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                levelEntity = levelMap[pRow][pCol + 1].getType();
                player.setDirection('right');
                player.wrapHorizontal();
                
                else
                {
                    if (levelEntity != 'wall')
                    {
                        player.setDirection('right');
                        player.move();
                    }
                }
                 
                        if (levelEntity == 'ball')
                        {
                            levelMap[pRow][pCol + 1].setType('power');
                            score += 1;
                            scoreDisplay.setString("Score: " + (std::to_string(score)));
                        }
                        else if (levelEntity == 'wall')
                        {
                            levelMap[pRow][pCol+1].setType('power');
                            score += 2;
                            scoreDisplay.setString("Score: " + (std::to_string(score)));
                            blinky.frightenGhost(fright);
                            blinkySpr.setTextureRect(fright); 
                            inky.frightenGhost(fright);
                            inkySpr.setTextureRect(fright); 
                            pinky.frightenGhost(fright);
                            pinkySpr.setTextureRect(fright); 
                            clyde.frightenGhost(fright);
                            clydeSpr.setTextureRect(fright); 
                        }
                    }

                    if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::R))
                    {
                        for (int a = 0; a < map_rows; a++)
                        {
                            for (int b = 0; b < map_cols; b++)
                            {
                                levelMap[a][b].resetMap(a, b);
                                if (levelMap[a][b].getType() == 'ball')
                                {
                                    levelMap[a][b].setSprite(ball);
                                }
                                if (levelMap[a][b].getType() == 'power')
                                {
                                    levelMap[a][b].setSprite(power);
                                }
                                if (levelMap[a][b].getType() == 'wall')
                                {
                                    levelMap[a][b].setSprite(wall);
                                }

                            }
                        }
                    }


            playerSprite = player.getSprite();
        }
        
        //INITIALIZE
        void main_game::Initialize(sf::RenderWindow* window)
        {
            sf::Font MyFont;
            MyFont.loadFromFile("arial.ttf");

            sf::Text scores_txt("Score:", MyFont, 20U);
            scores_txt.setPosition(4, 2);
            scores_txt.setColor(sf::Color(255, 255, 0));

            sf::Text score_txt(to_string(score), MyFont, 20U);
            score_txt.setPosition(65, 2);
            score_txt.setColor(sf::Color(255, 255, 0));

            sf::Text lives_txt("Lives:", MyFont, 20U);
            lives_txt.setPosition(135, 2);
            lives_txt.setColor(sf::Color(255, 255, 0));

            
        }

        //UPDATE
        void main_game::Update(sf::RenderWindow* window)
        {
            manager->Update();
            if (((mainCharacter*)this->manager->Get("mainCharacter"))->Lives() < 1)
            {
                coreState.SetState(new game_over());
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
            {
                coreState.SetState(new main_menu());
            }
            
        }

        //RENDER
        void main_game::Render(sf::RenderWindow* window)
        {
            this->score.setString("Score: " + std::to_string(((mainCharacter*)this->manager->Get("mainCharacter"))->Score()));
            this->lives.setString("Lives: " + std::to_string(((mainCharacter*)this->manager->Get("mainCharacter"))->Lives()));
            
            manager->Render(window);
            window->draw(this->score);
            window->draw(this->lives);
        }
        void main_game::Destroy(sf::RenderWindow* window)
        {
            delete manager;
        }
        
