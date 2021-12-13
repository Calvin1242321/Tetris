
#include "Headers/Tetris.h"



Tetris::Tetris()
{
}

Tetris::~Tetris()
{
}

int Tetris::setup_shape(pos a[])
{
	srand(time(NULL));

	int choise = rand() % 7;		// Pick a num at random as the first shape.
	j = 0;
	counter_move = 0;
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
// 
void Tetris::rotate_assist(int s_Mxn, int shape[][4], pos a[])
{
	if (j != s_Mxn - 1)	j++;
	else j = 0;

	for (int i = 0;i < 4;i++)
	{
		a[i].x = counter_move + shape[j][i] % 4;
		a[i].y = shape[j][i] / 4;
	}
}

//	last modified:	Dec/13/2021
//	need to check if exceed size of field.
void Tetris::move(pos a[], char dir)
{
	int k = 0;
	if (dir == 'r')	k = 1;
	else if (dir == 'l') k = -1;
	counter_move += k;
	//if (check())
	for (int i = 0;i < 4;i++)
		a[i].x += k;
}