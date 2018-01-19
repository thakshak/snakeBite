#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include "Grid.h"
#include "Snake.h"
#include "Food.h"

using namespace std;

int getRand(int mx)
{
    return rand()%mx;
}
int main()
{
    int x_max = 20, y_max = 20;
    int t1 = 0, t2 = -1;
    int score=-1,speed=500;
    bool food_available = 0;
    char mov = 'a';
    Grid *board = new Grid(x_max, y_max);
    Snake *python = new Snake(x_max/2, y_max/2);
    Food *food;
    board->addSnake(python);
    srand (time(NULL));
    while(1)
    {
        if(!food_available)
        {
            food = new Food(getRand(x_max), getRand(y_max), 235);
            board->addFood(food);
            food_available = 1;
            score++;
        }

        system("CLS");
        if(board->clearGrid()==0)
        {
            cout<<"GAME OVER"<<endl;
            cout<<"SCORE: "<<score;
            return 0;
        }
        board->print();
        cout<<endl<<"SCORE: "<<score;
        Sleep(speed-(score*5));
        if(_kbhit())
        {
            switch(_getch())
            {
            case 'w': mov ='w';
                    t1=-1;
                    t2=0;
            break;
            case 'a': mov ='a';
                    t1=0;
                    t2=-1;
            break;
            case 's': mov ='s';
                    t1=1;
                    t2=0;
            break;
            case 'd': mov ='d';
                    t1=0;
                    t2=1;
            break;
            case 'x': return 0;
            default : break;
            }
        }
        if(python->head->x_pos+t1 == food->x_pos && python->head->y_pos+t2 == food->y_pos)
        {
            python->eat(food);
            food_available = 0;
        }
        else python->moveSnake(t1,t2);
    }
    return 0;
}
