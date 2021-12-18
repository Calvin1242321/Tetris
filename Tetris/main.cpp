//	project:			Tetris using SFML
//	project started:	Dec/11/2021
//	Contact:			Calvin1242321	zxc1242321@gmail.com
#include <iostream>
#include <stdlib.h>						// for rand
#include <time.h>						// for rand
#include "Headers/GlobalVarible.h"
#include "Headers/Coordinate.h"
#include "Headers/Tetris.h"
#include "SFML/Graphics.hpp"

using namespace sf;

int main(void)
{
	sf::RenderWindow window(sf::VideoMode(1920, 990),"The Tetris");

	Tetris tetris;
	Texture blockTexture;
	Texture background;
	blockTexture.loadFromFile("Images/Tetris.png");
	background.loadFromFile("Images/Tboard.png");

	Sprite board(background);
	Sprite block(blockTexture);
	

	clock_t start, end;
	start = clock();

	pos a[4];
	int color = rand() % 4;
	int typ = tetris.setup_shape(a, &color);
	
	srand(time(NULL));
	while(window.isOpen())
	{
		end = clock();
		std::cout << start << std::endl;
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)		window.close();
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Down)
				{
					//	acceslation falling time
				}
				if (event.key.code == Keyboard::Up)
					tetris.rotate(a, typ);
				if (event.key.code == Keyboard::Left)
					tetris.move(a, 'l');
				if (event.key.code == Keyboard::Right)
					tetris.move(a, 'r');
				if (event.key.code == Keyboard::Space)
				{
					tetris.drop_ins(a, color);
					typ = tetris.setup_shape(a, &color);
				}
			}	
		}

		//	display where is current shape would locate.
		
		

		// fall
		if (end - start > FALL_TIME)
		{
			start = end;
			tetris.falling(a);
		}



		window.clear();
		window.draw(board);
		
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

		for (int i = 0;i < 4;i++)
		{
			block.setTextureRect(IntRect(color * BLOCKSIZE, 0, BLOCKSIZE, BLOCKSIZE));
			block.setPosition(LEFTSPACE + a[i].x * BLOCKSIZE, TOPSPACE + a[i].y * BLOCKSIZE);
			window.draw(block);
		}
		
		window.display();
	}
	return 0;
}
