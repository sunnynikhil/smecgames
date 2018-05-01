#include"snake.h"
#include"pacman.h"
#include"quiz.h"
#include"smechead.h"
int main()
{
    HANDLE in,out;
  DWORD info;
    CONSOLE_SCREEN_BUFFER_INFO scrinfo;
    INPUT_RECORD inp;
    COORD pos={25,17};
    int i,j;
    SetConsoleTitle("SMEC");
    in=GetStdHandle(STD_INPUT_HANDLE);
    out=GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(out,&scrinfo);
    printstr(22,8,"smec games",219,_RED);
    SetConsoleCursorPosition(out,pos);
    system("pause");
   SetConsoleCursorPosition(out,zerozero);
    initializegame();
    return 0;
}
