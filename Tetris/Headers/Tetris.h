//    Class:                Tetris
//    function:            rotate, move, drop
//    project started:    Dec/13/2021
//    Contact:            Calvin1242321    zxc1242321@gmail.com
#ifndef _PIECE_
#define _PIECE_

#pragma once
#include "Headers/GlobalVarible.h"
#include "Headers/Coordinate.h"
#include "Headers/Game.h"
#include <stdlib.h> 
#include <time.h>
#include <random>
#include <queue>

class Tetris
{
public:
    Tetris();
    ~Tetris();

    void rotate(Position a[], int index);
    void rotate_assist(int s_Mxn, int shape[][4], Position a[], bool& isSucess);
    void setup_shape(Position a[], int* color);
    void set_assist(int shape[][4], Position a[]);
    void set_assist(int shape[][4], Position a[], int parameter);
    void move(Position a[], char dir);
    void drop_ins(Position a[], int color);
    void show_locate(Position a[]);
    void clean();
    void clean_assist(int i);
    void set_preview(int r[], Position f[][4]);
    void set_previewPos(int r[], Position a[][4]);

    bool check_availble(Position a[]);
    bool falling(Position a[], int color);

    int popAndSet(Position a[]);
private:
    int needRotateForm = 0;
public:
    int cleaned = 0;
    std::queue<int> piecesQueue;
    int counter_move = 0;
    int counter_fall = 0;

    int shape_I[globalVariables::I_FORMNUM][globalVariables::SQUARES_COMPOSED] = {
        {1, 5, 9, 13},
        {4, 5, 6, 7},
    };
    int shape_I_2[globalVariables::I_FORMNUM][globalVariables::SQUARES_COMPOSED] = {
        {1, 5, 9, 13},
        {0, 1, 2, 3},
    };

    int shape_O[1][globalVariables::SQUARES_COMPOSED] = {
        {1, 2, 5, 6},
    };

    int shape_L[globalVariables::L_FORMNUM][globalVariables::SQUARES_COMPOSED] = {
        {0, 1, 2, 4},
        {0, 1, 5, 9},
        {2, 4, 5, 6},
        {1, 5, 9, 10},
    };
    int shape_J[globalVariables::J_FORMNUM][globalVariables::SQUARES_COMPOSED] = {
        {0, 4, 5, 6},
        {2, 1, 5, 9},
        {10, 4, 5, 6},
        {1, 5, 9, 8},
    };
    int shape_S[globalVariables::S_FORMNUM][globalVariables::SQUARES_COMPOSED] = {
        {1, 2, 4, 5},
        {0, 4, 5, 9},
    };
    int shape_Z[globalVariables::S_FORMNUM][globalVariables::SQUARES_COMPOSED] =
    {
        {0, 1, 5, 6},
        {2, 5, 6, 9},
    };
    int shape_T[globalVariables::T_FORMNUM][globalVariables::SQUARES_COMPOSED] = {
        {1, 5, 6, 9},
        {4, 5, 6, 9},
        {1, 4, 5, 9},
        {1, 4, 5, 6},
    };
    int field[globalVariables::HEIGHT][globalVariables::WIDTH];    // empty: -1
    int ghostfield[globalVariables::HEIGHT][globalVariables::WIDTH];    // empty: -1
};

#endif // !_PIECE_


