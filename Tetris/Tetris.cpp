
#include "Headers/Tetris.h"

#include <iostream>			// for testing, after finished this class you should delete this line.

Tetris::Tetris()
{
	for (int i = 0;i < HEIGHT;i++)
		for (int j = 0;j < WIDTH;j++)	field[i][j] = -1;
}

Tetris::~Tetris()
{
}


//	last modified:	Dec/19/2021
//	Creator:		Calvin1242321
//	function:		Pick a shape randomly then return that shape.
//	lack:			1. It should follow the rules of tetris design.
//					2. Using queue to preview next 4 shapes. 
int Tetris::setup_shape(pos a[], int* color)
{
	// reset
	j = 0;
	counter_move = 0;
	counter_fall = 0;
	

	srand(time(NULL));

	int choise = rand() % 7;		// Pick a num at random as the first shape.
	*color = rand() % 4;
	
	switch (choise)
	{
	case 0:
		set_assist(shape_I, a);
		break;
	case 1:
		set_assist(shape_O, a);
		break;
	case 2:
		set_assist(shape_L, a);
		break;
	case 3:
		set_assist(shape_J, a);
		break;
	case 4:
		set_assist(shape_S, a);
		break;
	case 5:
		set_assist(shape_Z, a);
		break;
	case 6:
		set_assist(shape_T, a);
		break;
	default:
		break;
	}
	
	return choise;
}
void Tetris::set_assist(int shape[][4], pos a[])
{
	for (int i = 0;i < 4;i++)
	{
		a[i].x = shape[0][i] % 4;
		a[i].y = shape[0][i] / 4;
	}
}

//	last modified:	Dec/19/2021
//	Creator:		Calvin1242321
//	status:			It's working.
void Tetris::rotate(pos a[], int index)
{
	switch (index)
	{
	case 0:
		rotate_assist(I_FORMNUM, shape_I, a);
		break;
	case 1:
		rotate_assist(O_FORMNUM, shape_O, a);
		break;
	case 2:
		rotate_assist(L_FORMNUM, shape_L, a);
		break;
	case 3:
		rotate_assist(J_FORMNUM, shape_J, a);
		break;
	case 4:
		rotate_assist(S_FORMNUM, shape_S, a);
		break;
	case 5:
		rotate_assist(Z_FORMNUM, shape_Z, a);
		break;
	case 6:
		rotate_assist(T_FORMNUM, shape_T, a);
		break;
	default:
		break;
	}
}
void Tetris::rotate_assist(int s_Mxn, int shape[][4], pos a[])
{
	if (j != s_Mxn - 1)	j++;
	else j = 0;

	pos t[4];
	for (int i = 0;i < 4;i++)	t[i] = a[i];

	for (int i = 0;i < 4;i++)
	{
		t[i].x = counter_move + shape[j][i] % 4;
		t[i].y = counter_fall + shape[j][i] / 4;
	}
	if (check_availble(t))
		for (int i = 0;i < 4;i++)	a[i] = t[i];
}


//	last modified:	Dec/19/2021
//	Creator:		Calvin1242321
//	status:			It's working.
void Tetris::move(pos a[], char dir)
{
	pos t[4];
	for (int i = 0;i < 4;i++)	t[i] = a[i];

	int k = 0;
	if (dir == 'r')	k = 1;
	else if (dir == 'l') k = -1;
	counter_move += k;
	
	for (int i = 0;i < 4;i++)
		t[i].x += k;
	if (check_availble(t))
		for (int i = 0;i < 4;i++)	a[i] = t[i];
}

//	creator:	Calvin1242321	Dec/19/2021
//	function:
//	return true --> position is availble
//	return false --> Not availble
bool Tetris::check_availble(pos a[])
{
	for (int i = 0;i < 4;i++)
	{
		if (a[i].y >= HEIGHT)	return false;
		if (field[a[i].y][a[i].x] != -1)	return false;
		if (a[i].x < 0 || a[i].x >= WIDTH)	return false;
	}
	return true;
}

//	last modified:	DEC/19/2021
//	Creator:		Calvin1242321
//	status:			It's working.	
void Tetris::drop_ins(pos a[], int color)
{
	pos t[4];
	for(int i = 0;i < 4;i++)	t[i] = a[i];

	while (true)
	{
		for (int i = 0;i < 4;i++)	t[i].y++;
		if (check_availble(t))
			for (int i = 0;i < 4;i++)	a[i] = t[i];
		else
			break;
	}
	for (int i = 0;i < 4;i++)
	{
		field[a[i].y][a[i].x] = color;
	}
}


//	last modified:	DEC/19/2021
//	Creator:		Calvin1242321
//	status:			It's working.
void Tetris::falling(pos a[])
{
	pos t[4];
	for (int i = 0;i < 4;i++)	t[i] = a[i];

	for (int i = 0;i < 4;i++)	t[i].y++;
	if (check_availble(t))
	{
		for (int i = 0;i < 4;i++)	a[i] = t[i];
		counter_fall++;
	}
}



//	last modified:	DEC/19/2021
//	Creator:		Calvin1242321
//	status:			It's not working.	
void Tetris::show_locate(pos a[], int color)
{
	pos t[4];
	for (int i = 0;i < 4;i++)	t[i] = a[i];
	int c = 0;
	while (c < 20)
	{
		c++;
		for (int i = 0;i < 4;i++)	t[i].y++;
		if (!check_availble(t))	break;	
	}
	for (int i = 0;i < 4;i++)
	{
		//	abcde[t[i].y][t[i].x] = color;				abcde must be clean when every loop is started.
	}
}
