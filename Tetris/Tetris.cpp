
#include "Headers/Tetris.h"
#include <iostream>            // for testing, after finished this class you should delete this line.

Tetris::Tetris()
{
    for (int i = 0;i < globalVariables::HEIGHT;i++)
    {
        for (int j = 0;j < globalVariables::WIDTH;j++)
        {
            ghostfield[i][j] = -1;
            field[i][j] = -1;
        }
    }

    int x = 0;
    srand(time(NULL));
    for (int i = 0;i <= globalVariables::PREVIEW_NUM;i++)
    {
        x = rand() % 7;
        piecesQueue.push(x);
    }
    
}

Tetris::~Tetris()
{
}

//    last modified:    Dec/22/2021
//    Creator:         Calvin1242321
//    function:        Set the first tetromino.
int Tetris::popAndSet(Position a[])
{
    int x = piecesQueue.front();
    piecesQueue.pop();

    switch (x)
    {
    case 0:
        set_assist(shape_J, a);
        break;
    case 1:
        set_assist(shape_S, a);
        break;
    case 2:
        set_assist(shape_Z, a);
        break;
    case 3:
        set_assist(shape_O, a);
        break;
    case 4:
        set_assist(shape_T, a);
        break;
    case 5:
        set_assist(shape_I, a);
        break;
    case 6:
        set_assist(shape_L, a);
        break;
    default:
        break;
    }
    return x;
}


//    last modified:    Dec/12/2021
//    Creator:        Calvin1242321
//    function:        Pick a shape randomly then return that shape.
void Tetris::setup_shape(Position a[], int* color)
{
    // reset
    needRotateForm = 0;
    counter_move = 0;
    counter_fall = 0;
    

    srand(time(NULL));

    int choice = rand() % 7;
    piecesQueue.push(choice);
    *color = piecesQueue.front();
    piecesQueue.pop();
    switch (*color)
    {
    case 0:
        set_assist(shape_J, a);
        break;
    case 1:
        set_assist(shape_S, a);
        break;
    case 2:
        set_assist(shape_Z, a);
        break;
    case 3:
        set_assist(shape_O, a);
        break;
    case 4:
        set_assist(shape_T, a);
        break;
    case 5:
        set_assist(shape_I, a);
        break;
    case 6:
        set_assist(shape_L, a);
        break;
    default:
        break;
    }

}
void Tetris::set_assist(int shape[][4], Position a[])
{
    for (int i = 0;i < 4;i++)
    {
        a[i].x = shape[0][i] % 4;
        a[i].y = shape[0][i] / 4;
    }
}
void Tetris::set_assist(int shape[][4], Position a[], int parameter)
{
    for (int i = 0;i < 4;i++)
    {
        a[i].x = shape[parameter][i] % 4;
        a[i].y = shape[parameter][i] / 4;
    }
}

//    last modified:    Dec/19/2021
//    Creator:        Calvin1242321
//    function:        Rotate the falling piece.
//    status:            It's working.
void Tetris::rotate(Position a[], int index)
{
    bool isSuccess = true;
    switch (index)
    {
    case 0:
        rotate_assist(globalVariables::J_FORMNUM, shape_J, a, isSuccess);
        break;
    case 1:
        rotate_assist(globalVariables::S_FORMNUM, shape_S, a, isSuccess);
        break;
    case 2:
        rotate_assist(globalVariables::Z_FORMNUM, shape_Z, a, isSuccess);
        break;
    case 3:
        rotate_assist(globalVariables::O_FORMNUM, shape_O, a, isSuccess);
        break;
    case 4:
        rotate_assist(globalVariables::T_FORMNUM, shape_T, a, isSuccess);
        break;
    case 5:
        rotate_assist(globalVariables::I_FORMNUM, shape_I, a, isSuccess);
        if (!isSuccess) {
            rotate_assist(globalVariables::I_FORMNUM, shape_I_2, a, isSuccess);
        }
        break;
    case 6:
        rotate_assist(globalVariables::L_FORMNUM, shape_L, a, isSuccess);
        break;
    default:
        break;
    }
}

void Tetris::rotate_assist(int form_Num, int shape[][4], Position a[], bool &isSucess)
{    
    //if (needRotateForm != form_Num - 1)    needRotateForm++;
    //    else needRotateForm = 0;
    if (isSucess) {
        needRotateForm = ((needRotateForm + 1) % form_Num);
    }

    Position t[4];
    for (int i = 0;i < 4;i++)    t[i] = a[i];        
    for (int i = 0;i < 4;i++)
    {
        t[i].x = counter_move + shape[needRotateForm][i] % 4;
        t[i].y = counter_fall + shape[needRotateForm][i] / 4;
    }
    if (check_availble(t)) {
        for (int i = 0; i < 4; i++)    a[i] = t[i];
    }
    else{
        isSucess = false;
    }    
}


//    last modified:    Dec/19/2021
//    Creator:        Calvin1242321
//    function:        Move the falling piece.
//    status:            It's working.
void Tetris::move(Position a[], char dir)
{                            // l or r
    Position t[4];
    for (int i = 0;i < 4;i++)    t[i] = a[i];

    int k = 0;
    if (dir == 'r')    k = 1;
    else if (dir == 'l') k = -1;
    
    for (int i = 0;i < 4;i++)
        t[i].x += k;
    if (check_availble(t))
    {
        for (int i = 0;i < 4;i++)    a[i] = t[i];
        counter_move += k;
    }
        
}

//    creator:    Calvin1242321    Dec/19/2021
//    function:
//    return true --> position is availble
//    return false --> Not availble
bool Tetris::check_availble(Position a[])
{
    for (int i = 0;i < 4;i++)
    {
        if (a[i].y >= globalVariables::HEIGHT)    return false;
        if (field[a[i].y][a[i].x] != -1)    return false;
        if (a[i].x < 0 || a[i].x >= globalVariables::WIDTH)    return false;
    }
    return true;
}

//    last modified:    DEC/19/2021
//    Creator:        Calvin1242321
//    function:        Hard drop.
//    status:            It's working.    
void Tetris::drop_ins(Position a[], int color)
{
    Position t[4];
    for(int i = 0;i < 4;i++)    t[i] = a[i];

    while (true)
    {
        for (int i = 0;i < 4;i++)    t[i].y++;
        if (check_availble(t))
            for (int i = 0;i < 4;i++)    a[i] = t[i];
        else
            break;
    }
    for (int i = 0;i < 4;i++)
    {
        field[a[i].y][a[i].x] = color;
    }
    clean();
}


//    last modified:    DEC/19/2021
//    Creator:        Calvin1242321
//    function:        Make the current tetromino you countrol falling.
//    status:            It's working.
bool Tetris::falling(Position a[], int color)
{
    Position t[4];
    for (int i = 0;i < 4;i++)    t[i] = a[i];

    for (int i = 0;i < 4;i++)    t[i].y++;
    if (check_availble(t))            //If 'check_availble' is true, tetromino keep falling.
    {
        for (int i = 0;i < 4;i++)    a[i] = t[i];
        counter_fall++;
    }
    else
    {
        for (int i = 0;i < 4; i++)
            field[a[i].y][a[i].x] = color;
        clean();
        return true;
    }
    return false;
}


//    last modified:    DEC/22/2021
//    Creator:        Calvin1242321
//    function:        Show the place the falling piece would locate. 
//    status:            It's working.    
void Tetris::show_locate(Position a[])
{
    for (int i = 0;i < globalVariables::HEIGHT;i++)
        for (int j = 0;j < globalVariables::WIDTH;j++)    ghostfield[i][j] = -1;

    Position t[4];
    for (int i = 0;i < 4;i++)    t[i] = a[i];
    int c = 0;
    while (true)
    {
        c++;
        for (int i = 0;i < 4;i++)    t[i].y++;
        if (!check_availble(t))
        {
            for (int i = 0;i < 4;i++)    t[i].y--;
            break;
        }
    }
    for (int i = 0;i < 4;i++)
    {
        ghostfield[t[i].y][t[i].x] = 1;                
    }
}


//    last modified:    DEC/19/2021
//    Creator:        Calvin1242321
//    function:        clean row when it is full.
//    status:            It's working.    
void Tetris::clean()
{
    for (int i = globalVariables::HEIGHT - 1; i >= 0;i--)
    {
        bool shouldclear = true;        
        for (int j = 0;j < globalVariables::WIDTH;j++)
        {
            if (field[i][j] == -1)
            {
                shouldclear = false;
                break;
            }    
        }
        if (shouldclear)
        {
            cleaned++;
            clean_assist(i);
            i = globalVariables::HEIGHT;        // restart this loop.
        }
    }
}
void Tetris::clean_assist(int i )
{
    if (i != 0)
    {
        for (int j = 0;j < globalVariables::WIDTH;j++)
            field[i][j] = field[i - 1][j];
        clean_assist(i - 1);
    }
}


//    last modified:    DEC/19/2021
//    Creator:        Calvin1242321
//    function:        Display the next tetromino.
//    status:            It's working.    
void Tetris::set_preview(int r[], Position f[][4])
{
    std::queue<int> a;
    a = piecesQueue;
    std::cout << "\n";
    int i = 0;
    while (!a.empty())
    {
        r[i] = a.front();
        i++;
        a.pop();
    }
    set_previewPos(r, f);
}
void Tetris::set_previewPos(int r[], Position a[][4])
{
    for (int i = 0;i < globalVariables::PREVIEW_NUM;i++)
    {
        switch (r[i])
        {
        case 0:
            set_assist(shape_J, a[i]);
            break;
        case 1:
            set_assist(shape_S, a[i]);
            break;
        case 2:
            set_assist(shape_Z, a[i]);
            break;
        case 3:
            set_assist(shape_O, a[i]);
            break;
        case 4:
            set_assist(shape_T, a[i], 1);
            break;
        case 5:
            set_assist(shape_I, a[i], 1);
            break;
        case 6:
            set_assist(shape_L, a[i]);
            break;
        default:
            break;
        }
    }
}