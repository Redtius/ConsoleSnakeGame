#include "Snake.h"
#define WIDTH 80
#define HEIGHT 25
#include <windows.h>
#include <vector>

Snake::Snake(COORD pos,int vel)
{
    this->pos=pos;
    this->vel=vel;
    len=1;
    direction='n';
    body.push_back(pos);
}

void Snake::change_dir(char dir){direction=dir;}

void Snake::move_snake()
{
switch(direction)
{
  case 'u': pos.Y-=vel;break;
  case 'd':pos.Y+=vel;break;
  case 'l': pos.X-=vel;break;
  case 'r':pos.X+=vel;break;
}

body.push_back(pos);
if(body.size()>len) body.erase(body.begin());
}

vector<COORD> Snake::get_body()
{
    return body;
}


COORD Snake::get_pos(){return pos;}

bool Snake::eat_verify(COORD food_pos)
{
    if(pos.X==food_pos.X && pos.Y==food_pos.Y) return true;
    else return false;
}

int Snake::get_len(){return len;}

char Snake::get_dir(){return direction;}



void Snake::grow(){
    len++;
    }



bool Snake::collided(){
return(pos.X>WIDTH || pos.Y>HEIGHT || pos.X<1 || pos.Y<1);
}

