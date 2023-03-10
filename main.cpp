#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <time.h>
#define WIDTH 80
#define HEIGHT 25

#include "Snake.h"
#include "Food.h"

using namespace std;

Snake snake({WIDTH/2,HEIGHT/2},1);
Food food(snake.get_len());

void board()
{
    COORD snake_pos = snake.get_pos();
    COORD food_pos = food.get_pos();
    vector<COORD> snake_body=snake.get_body();
    for(int i = 0; i< HEIGHT; i++)
    {
        cout<< "\t\t*";
        for(int j =0;j<WIDTH-2;j++)
        {
            if(i==0 || i== HEIGHT-1) cout<<'*';
            else if(j+1==snake_pos.X && i==snake_pos.Y)
            {
                cout <<'o';
            }
            else if(j+1==food_pos.X && i==food_pos.Y) cout <<'#';
            else
            {
                bool isbodypart = false;
                for(int k=0;k<snake_body.size();k++)
                {
                    if(i==snake_body[k].Y && j+1==snake_body[k].X)
                    {
                      cout << 'o';
                      isbodypart=true;
                      break;
                    }
                }
                if(!isbodypart) cout << ' ';
            }
        }
        cout<<"*\n";
    }
}

int main() {
    srand(time(NULL));
    bool game_over=false;
    while(!game_over)
    {
        board();
        if(kbhit())
        {
            switch(getch())
            {
                case 'z': snake.change_dir('u');break;
                case 's': snake.change_dir('d');break;
                case 'q': snake.change_dir('l');break;
                case 'd': snake.change_dir('r');break;
            }
        }
        snake.move_snake();

        if(snake.eat_verify(food.get_pos()))
        {
            food.gen_food(snake.get_len());
            snake.grow();
        }

        if(snake.collided())
        {
            game_over=true;
        }

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,0});
    }
}
