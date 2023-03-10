#ifndef SNAKE_H
#define SNAKE_H
#include <windows.h>
#include <vector>

using namespace std;

typedef struct node{
    COORD pos;
    struct node* next;
}maillon;


class Snake
{
private:
    COORD pos;
    int len;
    int vel;
    char direction;
    vector<COORD> body;

public:
    Snake(COORD,int);
    void change_dir(char dir);
    void move_snake();
    COORD get_pos();
    int get_len();
    char get_dir();
    vector<COORD> get_body();
    bool eat_verify(COORD food_pos);
    void grow();
    bool collided();
};

#endif // SNAKE_H
