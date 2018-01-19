#include "Food.h"
#include <cstdlib>


Food::Food()
{
    x_pos = y_pos = NULL;
    next = prev = NULL;
}
Food::Food(int x, int y, int dt )
{
    x_pos = x;
    y_pos = y;
    next = prev = NULL;
    data = dt;
}

