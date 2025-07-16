//    project:            Tetris using SFML
//    project started:    Dec/11/2021
//    Contact:            Calvin1242321    zxc1242321@gmail.com
#include <iostream>
#include <stdlib.h>                        // for rand
#include <time.h>                        // for rand
#include <string>

#include "Headers/GlobalVarible.h"
#include "Headers/Coordinate.h"
#include "Headers/Tetris.h"
#include "Headers/Game.h"
#include "SFML/Graphics.hpp"
#include "SFML/Network.hpp"
#include "SFML/Audio.hpp"

/*
int triggerEvent(sf::Event event, Tetris tetris, unsigned char *frameUnit) {
    if (event.type == sf::Event::Closed)        window.close();
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Down)
            *frameUnit = 1;
        if (event.key.code == sf::Keyboard::Up)
            tetris.rotate(squarePosition, currentPiece);
        if (event.key.code == sf::Keyboard::Left)
            tetris.move(squarePosition, 'l');
        if (event.key.code == sf::Keyboard::Right)
            tetris.move(squarePosition, 'r');
        if (event.key.code == sf::Keyboard::Space)
        {
            tetris.drop_ins(squarePosition, currentPiece);
            tetris.setup_shape(squarePosition, &currentPiece);
            tetris.set_preview(preview_piece, previewPosition);
        }
        if (event.key.code == sf::Keyboard::C)            // hold piece    not finished
        {
            tetris.setup_shape(squarePosition, &currentPiece);
            tetris.set_preview(preview_piece, previewPosition);
        }
    }
    return 0
}*/

int main(void)
{
    clock_t start, end;
    start = clock();

    int currentPiece = 0;

    bool spawnPiece = false;

    Position squarePosition[globalVariables::SQUARES_COMPOSED];
    Tetris tetris;
    currentPiece = tetris.popAndSet(squarePosition);

    Position previewPosition[globalVariables::PREVIEW_NUM][globalVariables::SQUARES_COMPOSED];
    int preview_piece[4];
    for (unsigned char i = 0; i < globalVariables::SQUARES_COMPOSED; i++) preview_piece[i] = -1;
    tetris.set_preview(preview_piece, previewPosition);

    sf::Text tline;
    sf::Font font;
    font.loadFromFile("fonts/t.otf");
    tline.setFont(font);
    tline.setCharacterSize(35);
    tline.setPosition(1400, 675);
    tline.setString(std::to_string(0));

    sf::Texture blockTexture;
    sf::Texture background;
    sf::Texture ghostT;
    blockTexture.loadFromFile("Images/Tetris.png");
    background.loadFromFile("Images/Tboard.png");
    ghostT.loadFromFile("Images/ghost.png");

    sf::Sprite board(background);
    sf::Sprite block(blockTexture);
    sf::Sprite ghost(ghostT);

    unsigned char frameUnit = 8;

    sf::RenderWindow window(sf::VideoMode(1920, 990), "The Tetris");
    while(window.isOpen())
    {
        end = clock();    
        sf::Event event;
        frameUnit = 8;            // level would change this parameter.
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)        window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Down)
                    frameUnit = 1;
                if (event.key.code == sf::Keyboard::Up)
                    tetris.rotate(squarePosition, currentPiece);
                if (event.key.code == sf::Keyboard::Left)
                    tetris.move(squarePosition, 'l');
                if (event.key.code == sf::Keyboard::Right)
                    tetris.move(squarePosition, 'r');
                if (event.key.code == sf::Keyboard::Space)
                {
                    tetris.drop_ins(squarePosition, currentPiece);
                    tetris.setup_shape(squarePosition, &currentPiece);
                    tetris.set_preview(preview_piece, previewPosition);
                }
                if (event.key.code == sf::Keyboard::C)            // hold piece    not finished
                {
                    tetris.setup_shape(squarePosition, &currentPiece);
                    tetris.set_preview(preview_piece, previewPosition);
                }
            }
        }

        tetris.show_locate(squarePosition);

        // fall
        if ( end - start > globalVariables::FALL_TIME * frameUnit) // fix FALL_TIME with deltatime
        {
            if (spawnPiece == false)
            {
                start = end;
                spawnPiece = tetris.falling(squarePosition, currentPiece);
            }
        }

        if (end - start > globalVariables::DELAY_TIME && spawnPiece == true)
        {
            spawnPiece = false;
            start = end;
            tetris.setup_shape(squarePosition, &currentPiece);
            tetris.set_preview(preview_piece, previewPosition);
        }
        tline.setString(std::to_string(tetris.cleaned));

        window.clear();
        window.draw(board);

        // field
        for (int i = 0;i < globalVariables::HEIGHT;i++)
        {
            for (int j = 0;j < globalVariables::WIDTH;j++)
            {
                if (tetris.field[i][j] == -1) continue;
                block.setTextureRect(sf::IntRect(tetris.field[i][j] * globalVariables::BLOCKSIZE, 0,
                                                 globalVariables::BLOCKSIZE, globalVariables::BLOCKSIZE));
                block.setPosition(globalVariables::LEFTSPACE + j * globalVariables::BLOCKSIZE,
                                  globalVariables::TOPSPACE + i * globalVariables::BLOCKSIZE);
                window.draw(block);
            }
        }

        // showing ghost piece
        for (int i = 0;i < globalVariables::HEIGHT;i++)
        {
            for (int j = 0;j < globalVariables::WIDTH;j++)
            {
                if (tetris.ghostfield[i][j] == -1) continue;
                ghost.setTextureRect(sf::IntRect(0 * globalVariables::BLOCKSIZE, 0, globalVariables::BLOCKSIZE, globalVariables::BLOCKSIZE));
                ghost.setPosition(globalVariables::LEFTSPACE + j * globalVariables::BLOCKSIZE, globalVariables::TOPSPACE + i * globalVariables::BLOCKSIZE);
                window.draw(ghost);
            }
        }
        // current
        for (int i = 0;i < 4;i++)
        {
            block.setTextureRect(sf::IntRect(currentPiece * globalVariables::BLOCKSIZE, 0, globalVariables::BLOCKSIZE, globalVariables::BLOCKSIZE));
            block.setPosition(globalVariables::LEFTSPACE + squarePosition[i].x * globalVariables::BLOCKSIZE,
                              globalVariables::TOPSPACE + squarePosition[i].y * globalVariables::BLOCKSIZE);
            window.draw(block);
        }

        // next preview
        for (int i = 0;i < 4;i++)
        {
            for (int j = 0;j < 4;j++)
            {
                if (preview_piece[j] == -1)    continue;
                block.setTextureRect(sf::IntRect(preview_piece[i] * globalVariables::BLOCKSIZE, 0, globalVariables::BLOCKSIZE, globalVariables::BLOCKSIZE));
                block.setPosition(globalVariables::PREVIEW_LEFT + previewPosition[i][j].x * globalVariables::BLOCKSIZE, globalVariables::TOPSPACE + 10 +
                    i * globalVariables::BLOCKSIZE * 3.5 + previewPosition[i][j].y * globalVariables::BLOCKSIZE);
                window.draw(block);
            }
        }
        
        window.draw(tline);
        window.display();
    }
    return 0;
}