//	project:			Tetris using SFML
//	project started:	Dec/11/2021
//	Contact:			Calvin1242321	zxc1242321@gmail.com
#include <iostream>
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
	block.setTextureRect(IntRect(0, 0, blocksize, blocksize));

	pos a[4];
	int typ = tetris.setup_shape(a);
	

	while(window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)		window.close();
			if (event.type == Event::KeyPressed)
			{
				
				if (event.key.code == Keyboard::Up)
					tetris.rotate(a, typ);
				if (event.key.code == Keyboard::Left)
					tetris.move(a, 'l');
				if (event.key.code == Keyboard::Right)
					tetris.move(a, 'r');
				if (event.key.code == Keyboard::Space)
					typ = tetris.setup_shape(a);

			}
			
		}

		//fall

		window.clear();
		window.draw(board);
		
		for (int i = 0;i < 4;i++)
		{
			block.setPosition(LEFTSPACE + a[i].x * blocksize, TOPSPACE + a[i].y * blocksize);
			window.draw(block);
		}
		window.display();
	}
	return 0;
}