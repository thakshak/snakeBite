#include "Snake.h"
#include <cstdlib>

Snake::Snake(int x, int y)
{
  head = new Food(x, y, 153);
  tail = new Food(x, y+1);
  head->next = tail;
  tail->prev = head;
  length = 2;
}

Snake::moveSnake(int t1, int t2)
{
    Food *temp = tail;
    tail = tail->prev;
    tail->next = NULL;
    temp->x_pos = head->x_pos+t1;
    temp->y_pos = head->y_pos+t2;
    head->data = 233;
    head->prev = temp;
    temp->next = head;
    head = temp;
    head->data = 153;
}
Snake::eat(Food* f)
{
    length++;
    head->data = 233;
    head->prev = f;
    f->next = head;
    head = f;
    head->data = 153;
}

