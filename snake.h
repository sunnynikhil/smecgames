#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include<time.h>
#include<ctype.h>
#include <windows.h>
#include <process.h>
#define up 72
#define down 80
#define left 75
#define right 77
int length;
int bend_no;
int len;
char key;
int life;

struct gird{
    int x;
    int y;
    int direction;
};

typedef struct gird coordinate;

coordinate head, bend[500],food,body[30];
void Move(void);
void Food(void);
void Left(void);
void Right(void);
void Bend(void);
void Boarder(void);
void record(void);
void Up(void);
void Down(void);
void ExitGame(void);
void load(void);
void Delay(long double);
void displayscores()
 {
 char name[20];
 int s;
 FILE *f;
 system("cls");
 f=fopen("score.txt","r");
 fscanf(f,"%s%d",&name,&s);
 printf("\n\n\t\t ");
 printf("\n\n\t\t %s has secured the Highest Score %d",name,s);
 printf("\n\n\t\t ");
 fclose(f);
 getch();
 }
 void writescores(int score,char plname[20])
 {

    int sc;
 char nm[20];
 FILE *f;
 system("cls");
 f=fopen("score.txt","r");
 fscanf(f,"%s%d",&nm,&sc);
 if (score>=sc)
   { sc=score;
     fclose(f);
     f=fopen("score.txt","w");
     fprintf(f,"%s\n%d",plname,sc);
     fclose(f);
   }
 }
 void recordfiles()
{char c;
   FILE *f;
   f=fopen("record.txt","r");
   do{
    putchar(c=getc(f));
   }
   while(c!=EOF);

    fclose(f);
    getch();
}
void Move()
{
    int a,i;

    do{

        Food();
        fflush(stdin);

        len=0;

        for(i=0;i<30;i++)

        {

            body[i].x=0;

            body[i].y=0;

            if(i==length)

            break;

        }

        Delay(length);

        Boarder();

        if(head.direction==right)

            Right();

        else if(head.direction==left)

            Left();

        else if(head.direction==down)

            Down();

        else if(head.direction==up)

            Up();

        ExitGame();

    }while(!kbhit());

    a=getch();

    if(a==27)

    {

        system("cls");

        exit(0);

    }
    key=getch();
    if((key==right&&head.direction!=left&&head.direction!=right)||(key==left&&head.direction!=right&&head.direction!=left)||(key==up&&head.direction!=down&&head.direction!=up)||(key==down&&head.direction!=up&&head.direction!=down))

    {

        bend_no++;
        bend[bend_no]=head;
        head.direction=key;
        if(key==up)
            head.y--;
        if(key==down)

            head.y++;

        if(key==right)

            head.x++;

        if(key==left)

            head.x--;

        Move();

    }

    else if(key==27)

    {

        system("cls");

        exit(0);

    }

    else

    {

        printf("\a");

        Move();

    }
}

void gotoxy(int x, int y)
{

 COORD coord;
 coord.X = x;
 coord.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void GotoXY(int x, int y)
{
    HANDLE a;
    COORD b;
    fflush(stdout);
    b.X = x;
    b.Y = y;
    a = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(a,b);
 }
void load(){
    int row,col,r,c,q;
    gotoxy(36,14);
    printf("loading...");
    gotoxy(30,15);
    for(r=1;r<=20;r++){
    for(q=0;q<=100000000;q++);
    printf("%c",177);}
}
void Down()
{
    int i;
    for(i=0;i<=(head.y-bend[bend_no].y)&&len<length;i++)
    {
        GotoXY(head.x,head.y-i);
        {
            if(len==0)
                printf("v");
            else
                printf("*");
        }
        body[len].x=head.x;
        body[len].y=head.y-i;
        len++;
    }
    Bend();
    if(!kbhit())
        head.y++;
}
void Delay(long double k)
{
    Score();
    long double i;
    for(i=0;i<=(10000000);i++);
}
void ExitGame()
{
    int i,check=0;
    for(i=4;i<length;i++)
        {
        if(body[0].x==body[i].x&&body[0].y==body[i].y)
        {
            check++;
        }
        if(i==length||check!=0)
            break;
    }
    if(head.x<=10||head.x>=70||head.y<=10||head.y>=30||check!=0)
    {
        life--;
        if(life>0)
        {
            head.x=25;
            head.y=20;
            bend_no=0;
            head.direction=right;
            Move();
        }
        else
        {
            system("cls");
            printf("Your Three lifes completed\nyour score is =%d\nWell played Better luck next time\nPress any key to quit the game\n",Scoreonly());
            records();
            exit(0);
        }
    }
}
void Food()
{
    if(head.x==food.x&&head.y==food.y)
    {
        length++;
        time_t a;
        a=time(0);
        srand(a);
        food.x=rand()%70;
        if(food.x<=10)
            food.x+=11;
        food.y=rand()%30;
        if(food.y<=10)

            food.y+=11;
    }
    else if(food.x==0)
            {
        food.x=rand()%70;
        if(food.x<=10)
            food.x+=11;
        food.y=rand()%30;
        if(food.y<=10)
            food.y+=11;
    }
}
void Left()
{
    int i;
    for(i=0;i<=(bend[bend_no].x-head.x)&&len<length;i++)
    {
        GotoXY((head.x+i),head.y);
       {
                if(len==0)
                    printf("<");
                else
                    printf("*");
        }
        body[len].x=head.x+i;
        body[len].y=head.y;
        len++;
    }
    Bend();
    if(!kbhit())
        head.x--;

}
void Right()
{
    int i;
    for(i=0;i<=(head.x-bend[bend_no].x)&&len<length;i++)
    {
        body[len].x=head.x-i;
        body[len].y=head.y;
        GotoXY(body[len].x,body[len].y);
        {
            if(len==0)
                printf(">");
            else
                printf("*");
        }
        len++;
    }
    Bend();
    if(!kbhit())
        head.x++;
}
void Bend()
{
    int i,j,diff;
    for(i=bend_no;i>=0&&len<length;i--)
    {
            if(bend[i].x==bend[i-1].x)
            {
                diff=bend[i].y-bend[i-1].y;
                if(diff<0)
                    for(j=1;j<=(-diff);j++)
                    {
                        body[len].x=bend[i].x;
                        body[len].y=bend[i].y+j;
                        GotoXY(body[len].x,body[len].y);
                        printf("*");
                        len++;
                        if(len==length)
                            break;
                    }
                else if(diff>0)
                    for(j=1;j<=diff;j++)
                    {
                        body[len].x=bend[i].x;
                        body[len].y=bend[i].y-j;
                        GotoXY(body[len].x,body[len].y);
                        printf("*");
                        len++;
                        if(len==length)
                            break;
                    }
            }
        else if(bend[i].y==bend[i-1].y)
        {
            diff=bend[i].x-bend[i-1].x;
            if(diff<0)
                for(j=1;j<=(-diff)&&len<length;j++)
                {
                    body[len].x=bend[i].x+j;
                    body[len].y=bend[i].y;
                    GotoXY(body[len].x,body[len].y);
                        printf("*");
                   len++;
                   if(len==length)
                           break;
               }
           else if(diff>0)
               for(j=1;j<=diff&&len<length;j++)
               {

                   printf("*");
                   body[len].x=bend[i].x-j;
                   body[len].y=bend[i].y;
                   GotoXY(body[len].x,body[len].y);
                       printf("*");
                   len++;
                   if(len==length)
                       break;
               }
       }
   }
}
void Boarder()
{
   system("cls");
   int i;
   GotoXY(food.x,food.y);
       printf("*");
   for(i=10;i<71;i++)
   {
       GotoXY(i,10);
           printf("!");
       GotoXY(i,30);
           printf("!");
   }
   for(i=10;i<31;i++)
   {
       GotoXY(10,i);
           printf("!");
       GotoXY(70,i);
       printf("!");
   }
}
void print()
{ int ch;
   printf("\t\t-----------------------------------------\n");
   printf("\t\tWelcome to the Snake game.(press any key to continue)\n");
   printf("\t\t-----------------------------------------\n");
  getch();
  printf(" \t\t 1 to start the game\n\n \t\t 2 for view records\n");
  scanf("%d",&ch);
   system("cls");
   if(ch==1){
   printf("\n**Game instructions:\n");
   printf("\n-> Use arrows to move the snake...\n\n-> your having three lifes\n\n-> you can pause game in middle by pressing any key and resume press the same key \n\n-> you want to exit the game press esc key. \n\n");
   printf("\n\nPress any key to play game...");
   if(getch()==27)
   exit(0);
   }
   else if(ch==2)
   {
       recordfiles();
       Print();
   }
}
void records(){
   char plname[20],nplname[20],cha,c;
   int i,j,px;
   FILE *info;
   info=fopen("recordsnake.txt","a+");
   getch();
   system("cls");
   printf("Enter your name\n");
   scanf("%[^\n]",plname);
   for(j=0;plname[j]!='\0';j++){
   nplname[0]=toupper(plname[0]);
   if(plname[j-1]==' '){
   nplname[j]=toupper(plname[j]);
   nplname[j-1]=plname[j-1];}
   else nplname[j]=plname[j];
   }
   nplname[j]='\0';
   fprintf(info,"player Name :%s\n",nplname);
   time_t mytime;
  mytime = time(NULL);
  fprintf(info," Date:%s",ctime(&mytime));
     fprintf(info,"score:%d\n",px=Scoreonly());
   for(i=0;i<=50;i++)
   fprintf(info,"%c",'_');
   fprintf(info,"\n");
   fclose(info);
   writescores(Scoreonly(),plname);
   printf("wanna see past records press 'y'\n");
   cha=getch();
   system("cls");
   if(cha=='y'){
   info=fopen("recordsnake.txt","r");
   do{
       putchar(c=getc(info));
       }while(c!=EOF);
       }
     fclose(info);
     getch();
     initializegame();
}
int Score()
{
   int score;
   GotoXY(20,8);
   score=length-5;
   printf("SCORE : %d",(length-5));
   score=length-5;
   GotoXY(50,8);
   printf("Life : %d",life);
   return score;
}
int Scoreonly()
{
int score=Score();
system("cls");
return score;
}
void Up()
{
   int i;
   for(i=0;i<=(bend[bend_no].y-head.y)&&len<length;i++)
   {
       GotoXY(head.x,head.y+i);
       {
           if(len==0)
               printf("^");
           else
               printf("*");
       }
       body[len].x=head.x;
       body[len].y=head.y+i;
       len++;
   }
   Bend();
   if(!kbhit())
       head.y--;
}
void snake()
{

    char key;
    print();
    system("cls");
    load();
    length=5;
    head.x=25;
    head.y=20;
    head.direction=right;
    Boarder();
    Food();
    life=3;
    bend[0]=head;
    Move();
    initializegame();
    }
