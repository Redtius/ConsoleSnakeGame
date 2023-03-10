#include "Food.h"
#include <windows.h>
#include <cstdlib>
#define WIDTH 80
#define HEIGHT 25

Food::Food(int len)
{
    gen_food(len);
}

void Food::gen_food(int len)
{
    int i;
    if(len<3)
    {
        pos.X= rand() % (WIDTH-1) + 1;
    pos.Y= rand() % (HEIGHT-1) + 1;
    }
    else{
    while(i>0){
      pos.X= rand() % (WIDTH-1) + 1;
       pos.Y= rand() % (HEIGHT-1) + 1;
       i--;
    }
    }
}

COORD Food::get_pos(){return pos;}
