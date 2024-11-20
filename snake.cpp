#include<iostream>
#include<windows.h>
#include<conio.h>

using namespace std;

bool gameover;
const int width=20;
const int height=20;
int x,y;
int fx,fy;
int score=0;
enum e {STOP=0, LEFT, RIGHT, UP, DOWN};
e dir;

void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

void setup(){
    gameover=false;
    dir=STOP;
    x=width/2;
    y=height/2;
    fx=rand() % width;
    fy=rand() % height;
    score = 0;
}
void draw(){
    system("cls");      //system("clear");
    ShowConsoleCursor(false);
    for(int i=0;i<width+2;i++){
        cout<<"#";
    }
    cout<<endl;

    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(j==0) cout<<"#";
            if(i==y && j==x) cout<<"o";
            else if(i==fy && j==fx) cout<<"f";
            else cout<<" ";

            if(j==width-1) cout<<"#";
        }
        cout<<endl;
    }

    for(int i=0;i<width+2;i++){
        cout<<"#";
    }
    cout<<endl;
    cout<<"score = "<<score;
}
void input(){
    if(_kbhit()){
        switch(_getch()){
            case 'a':
                dir = LEFT;
                break;
            case 'w':
                dir = UP;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'x':
                gameover=true;
                break;
        }
    }
}
void logic(){
    switch(dir){
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        default:
            break;
    }
    if (x > width || x<0 || y>height || y<0) gameover=true;
    if(x==fx && y==fy){
        score++;
        fx = rand() % width;  // Generate new food position
        fy = rand() % height;
    }
}

int main(){
    setup();
    while(!gameover){
        draw();
        input();
        logic();
    }
    return 0;
}
