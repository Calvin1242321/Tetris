//	project:			Tetris using SFML
//	project started:	Dec/11/2021
//	Contact:			Calvin1242321	zxc1242321@gmail.com
#include <iostream>
#include <stdlib.h>						// for rand
#include <time.h>						// for rand
#include <string>

#include "Headers/GlobalVarible.h"
#include "Headers/Coordinate.h"
#include "Headers/Tetris.h"
#include "Headers/Game.h"
#include "SFML/Graphics.hpp"
#include "SFML/Network.hpp"
#include "SFML/Audio.hpp"


int main(void)
{
	
	sf::RenderWindow window(sf::VideoMode(1920, 990),"The Tetris");
	/*
	Tetris tetris;
	Game game;
	Texture blockTexture;
	Texture background;
	Texture ghostT;
	blockTexture.loadFromFile("Images/Tetris.png");
	background.loadFromFile("Images/Tboard.png");
	ghostT.loadFromFile("Images/ghost.png");

	Sprite board(background);
	Sprite block(blockTexture);
	Sprite ghost(ghostT);
	
	clock_t start, end;
	start = clock();	

	pos block_pos[4];		//block pos
	pos next_pos[PREVIEW_NUM][4];
	int currentTetro = 0;
	int deltatime = 8;
	int next_arr[4];
	for (int i = 0;i < 4;i++)	next_arr[i] = -1;

	bool need_next = false;

	currentTetro = tetris.popAndSet(block_pos);
	tetris.set_preview(next_arr, next_pos);

	Text tline;
	Font font;
	font.loadFromFile("fonts/t.otf");
	tline.setFont(font);
	tline.setCharacterSize(35); // exprimée en pixels, pas en points !
	tline.setPosition(1400, 675);
	tline.setString(std::to_string(0));
	while(window.isOpen())
	{
		end = clock();	
		Event event;
		deltatime = 8;			// level would change this parameter.
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)		window.close();
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Down)
					deltatime = 1;
				if (event.key.code == Keyboard::Up)
					tetris.rotate(block_pos, currentTetro);
				if (event.key.code == Keyboard::Left)
					tetris.move(block_pos, 'l');
				if (event.key.code == Keyboard::Right)
					tetris.move(block_pos, 'r');
				if (event.key.code == Keyboard::Space)
				{
					tetris.drop_ins(block_pos, currentTetro);
					tetris.setup_shape(block_pos, &currentTetro);
					tetris.set_preview(next_arr, next_pos);
				}
				if (event.key.code == Keyboard::C)			// hold piece	not finished
				{
					tetris.setup_shape(block_pos, &currentTetro);
					tetris.set_preview(next_arr, next_pos);
				}
			}	
		}

		//	Displays the locatation of the falling piece. 
		tetris.show_locate(block_pos);

		// fall
		if ( end - start > FALL_TIME * deltatime ) // fix FALL_TIME with deltatime
		{
			if (need_next == false)
			{
				start = end;			
				need_next = tetris.falling(block_pos, currentTetro);
			}
		}
		
		if (end - start > DELAY_TIME && need_next == true)
		{
			need_next = false;
			start = end;
			tetris.setup_shape(block_pos, &currentTetro);
			tetris.set_preview(next_arr, next_pos);
		}
		tline.setString(std::to_string(tetris.cleaned));

		window.clear();
		window.draw(board);

		// field
		for (int i = 0;i < HEIGHT;i++)
		{
			for (int j = 0;j < WIDTH;j++)
			{
				if (tetris.field[i][j] == -1) continue;
				block.setTextureRect(IntRect(tetris.field[i][j] * BLOCKSIZE, 0, BLOCKSIZE, BLOCKSIZE));
				block.setPosition(LEFTSPACE + j * BLOCKSIZE, TOPSPACE + i * BLOCKSIZE);
				window.draw(block);
			}
		}

		// ghost
		for (int i = 0;i < HEIGHT;i++)
		{
			for (int j = 0;j < WIDTH;j++)
			{
				if (tetris.ghostfield[i][j] == -1) continue;
				ghost.setTextureRect(IntRect(0 * BLOCKSIZE, 0, BLOCKSIZE, BLOCKSIZE));
				ghost.setPosition(LEFTSPACE + j * BLOCKSIZE, TOPSPACE + i * BLOCKSIZE);
				window.draw(ghost);
			}
		}
		// current
		for (int i = 0;i < 4;i++)
		{
			block.setTextureRect(IntRect(currentTetro * BLOCKSIZE, 0, BLOCKSIZE, BLOCKSIZE));
			block.setPosition(LEFTSPACE + block_pos[i].x * BLOCKSIZE, TOPSPACE + block_pos[i].y * BLOCKSIZE);
			window.draw(block);
		}

		// next preview
		for (int i = 0;i < 4;i++)
		{
			for (int j = 0;j < 4;j++)
			{
				if (next_arr[j] == -1)	continue;
				block.setTextureRect(IntRect(next_arr[i] * BLOCKSIZE, 0, BLOCKSIZE, BLOCKSIZE));
				block.setPosition(PREVIEW_LEFT + next_pos[i][j].x * BLOCKSIZE,TOPSPACE + 10 +
					i * BLOCKSIZE * 3.5 + next_pos[i][j].y * BLOCKSIZE);
				window.draw(block);
			}
		}
		
		window.draw(tline);
		window.display();
	}*/
	return 0;
}