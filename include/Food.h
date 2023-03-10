#ifndef FOOD_H
#define FOOD_H
#include <windows.h>
#include <cstdlib>


class Food
{
private:
    COORD pos;

public :
    Food(int);
    void gen_food(int);
    COORD get_pos();

};

#endif // FOOD_H
