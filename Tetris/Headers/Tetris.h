#pragma once

//	Class:				Tetris
//	function:			rotate, move, drop
//	project started:	Dec/13/2021
//	Contact:			Calvin1242321	zxc1242321@gmail.com

#include "Headers/GlobalVarible.h"
#include "Headers/Coordinate.h"
#include "Headers/Game.h"
#include <stdlib.h> 
#include <time.h>   
#include <queue>


class Tetris
{
public:
	Tetris();
	~Tetris();
	
	void rotate(pos a[], int index);
	void rotate_assist(int s_Mxn, int shape[][4], pos a[], bool &isSucess);
	void setup_shape(pos a[], int* color);
	void set_assist(int shape[][4], pos a[]);
	void set_assist(int shape[][4], pos a[], int parameter);
	void move(pos a[], char dir);
	void drop_ins(pos a[], int color);
	void show_locate(pos a[]);
	void clean();
	void clean_assist(int i);
	void set_preview(int r[], pos f[][4]);
	void set_previewPos(int r[], pos a[][4]);

	bool check_availble(pos a[]);
	bool falling(pos a[], int color);
	
	int popAndSet(pos a[]);
private:
	int needRotateForm = 0;
public:
	int cleaned = 0;
	std::queue<int> tetromino;
	int counter_move = 0;
	int counter_fall = 0;

	int shape_I[I_FORMNUM][4] =
	{
		{1, 5, 9, 13},
		{4, 5, 6, 7},
	};
	int shape_I_2[I_FORMNUM][4] =
	{
		{1, 5, 9, 13},
		{0, 1, 2, 3},
	};

	int shape_O[1][4] =
	{
		{1, 2, 5, 6},
	};
	
	int shape_L[L_FORMNUM][4] =
	{
		{0, 1, 2, 4},
		{0, 1, 5, 9},
		{2, 4, 5, 6},
		{1, 5, 9, 10},
	};
	int shape_J[J_FORMNUM][4] =
	{
		{0, 4, 5, 6},
		{2, 1, 5, 9},
		{10, 4, 5, 6},
		{1, 5, 9, 8},
	};
	int shape_S[S_FORMNUM][4] =
	{
		{1, 2, 4, 5},
		{0, 4, 5, 9},
	};
	int shape_Z[S_FORMNUM][4] =
	{
		{0, 1, 5, 6},
		{2, 5, 6, 9},
	};
	int shape_T[T_FORMNUM][4] =
	{
		{1, 5, 6, 9},
		{4, 5, 6, 9},
		{1, 4, 5, 9},
		{1, 4, 5, 6},
	};
	int field[HEIGHT][WIDTH];	// empty: -1
	int ghostfield[HEIGHT][WIDTH];	// empty: -1
};

