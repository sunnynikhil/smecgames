#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<stdbool.h>
#include<windows.h>

#define ROW 22
#define COL 72
int score=0;

enum move {UP,DOWN,LEFT,RIGHT,STOP}direction;
enum ghost_move {UP1,DOWN1,LEFT1,RIGHT1,STOP1} ghost1_dir,ghost2_dir;

void move_car(enum move dir);
void ghost1_direction();
void ghost2_direction();
void ghost1_move(enum ghost_move g1_dir);
void ghost2_move(enum ghost_move g2_dir);

int car_1r,car_1c,car_2r,car_2c;
int ghost1_r, ghost1_c;
int ghost2_r,ghost2_c,ghost11,ghost22;


char grid[ROW][COL]= {
"***********************************************************************",
"*                                          &                          *",
"*   ********   *********   ***************   ********************     *",
"*   *      *   *       *   *             *   *                  *     *",
"*   *      *   *       *   *             *   *                  *     *",
"*   *      *   *       *   *             *   *                  *     *",
"*   *      *   *       *   *             *   *                  *     *",
"*   ********   *********   ***************   ********************     *",
"*                                ::                                   *",
"*   ****************************   ******************************     *",
"*   *                          *   *                            *     *",
"*   *                          *   *                            *     *",
"*   *                          *   *                            *     *",
"*   *                          *   *                            *     *",
"*   *                          *   *                            *     *",
"*   *                          *   *                            *     *",
"*   *                          *   *                            *     *",
"*   *                          *   *                            *     *",
"*   ****************************   ******************************     *",
"*                 @                                                   *",
"***********************************************************************"};

void print_grid();
void displayscorep()
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
void writescorep(int score, char plnm[20])
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
     fprintf(f,"%s\n%d",nm,sc);
     fclose(f);
   }
 }
void Print()
{
   printf("\t-----------------------------------------\n");
   printf("\tWelcome to the Pacman game.(press any key to continue)\n");
   printf("\t-----------------------------------------\n");
   printf("**Game intsructions\n\n->your having a car \n\n-> one ghost is following you\n\n->you have to escape from ghost\n\n *easy game right(press any key to play)\n");
getch();
}
void pacman()
{
Print();
direction= STOP;
ghost1_dir = STOP1;
ghost2_dir = STOP1;
int i,count=20;
car_1r = 8;
car_1c =33;
car_2r = 8;
car_2c = 34;
ghost1_r=1;
ghost1_c=43;
ghost2_r=19;
ghost2_c=18;
char ch;
 print_grid();
ghost1_direction();
ghost2_direction();

 while(count)
 {
    if(_kbhit()){

       ch=_getch();
     switch(ch)
      {
        case 'd':

                direction=RIGHT;
                break;


        case 'a':

                direction=LEFT;
                break;


        case 'w':

                direction = UP;
                break;


        case 's':

                direction = DOWN;
                break;


        default:;

      }
    }

    if(grid[ghost1_r][ghost1_c]==grid[car_1r][car_1c]||
       grid[ghost1_r][ghost1_c]==grid[car_2r][car_2c])
    {
        printf("\n\t**GAME OVER**\n");
        record();
        break;
    }
    move_car(direction);
    ghost1_move(ghost1_dir);
    ghost2_move(ghost2_dir);
    Beep(400,150);
system("cls");
    print_grid();


 }
return 0;
}
void record(){
   char plname[20],nplname[20],cha,c;
   int i,j,px;
   FILE *info;
   info=fopen("recordpacman.txt","a+");
   getch();
   system("cls");
   printf("Enter your name\n");
   scanf("%s",plname);
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
     fprintf(info,"score:%d\n",score);
   for(i=0;i<=50;i++)
   fprintf(info,"%c",'_');
   fprintf(info,"\n");
   fclose(info);
   writescorep(score,plname);
   printf("wanna see past records press 'y'\n");
   cha=getch();
   system("cls");
   if(cha=='y'){
   info=fopen("recordpacman.txt","r");
   do{
       putchar(c=getc(info));
       }while(c!=EOF);
       }
     fclose(info);
}


void print_grid()
{
    int i;

    for(i=0;i<ROW;i++)
    printf("%s\n",grid[i]);
    score=car_1r+car_1c;
    printf("-----------------------------------------------\n");
    printf("\n\tTo move the car use keys\n\ta for left\n\ts for down\n\tw for up\n\td for right\n");
    printf("------------------------------------------------\n");
    printf("\tscore=%d",score);
}
void move_car(enum move dir)
{
    if(dir==UP)
    {
        if(grid[car_1r-1][car_1c]!= '*'& grid[car_2r-1][car_2c]!='*')
        {
           grid[car_1r][car_1c]=' ';
           grid[car_1r-1][car_1c]=':';
           grid[car_2r][car_2c]=' ';
           grid[car_2r-1][car_2c]=':';
           car_1r--;
           car_2r--;
        }
    }
    else if(dir==DOWN)

    {
        if(grid[car_1r+1][car_1c]!= '*'& grid[car_2r+1][car_2c]!='*')
      {
           grid[car_1r][car_1c]=' ';
           grid[car_1r+1][car_1c]=':';
           grid[car_2r][car_2c]=' ';
           grid[car_2r+1][car_2c]=':';
           car_1r++;
           car_2r++;

      }
    }
    if(dir==LEFT)
    {
       if(grid[car_1r][car_1c-1]!= '*'& grid[car_2r][car_2c-1]!='*')
       {
           grid[car_1r][car_1c]=' ';
           grid[car_1r][car_1c-1]=':';
           grid[car_2r][car_2c]=' ';
           grid[car_2r][car_2c-1]=':';
           car_1c--;
           car_2c--;
      }
    }
    else if(dir==RIGHT)

    {
       if(grid[car_1r][car_1c+1]!= '*'& grid[car_2r][car_2c+1]!='*')
       {
           grid[car_2r][car_2c]=' ';
           grid[car_2r][car_2c+1]=':';
           grid[car_1r][car_1c]=' ';
           grid[car_1r][car_1c+1]=':';

           car_1c++;
           car_2c++;
       }
    }
}
void ghost1_direction()
{
    int ghost1;
    srand((unsigned) time(NULL));

    ghost1=(rand()%4)+1;


    if(ghost1==1)
        ghost1_dir=UP1;
        else if(ghost1==2)
            ghost1_dir=DOWN1;
    if(ghost1==3)
       ghost1_dir=LEFT1;
       else
        ghost1_dir=RIGHT1;
}

void ghost2_direction()
    {
        int ghost2;

        ghost2=(rand()%4)+1;

        switch(ghost2)
        {
        case 1:
        case 3:


                ghost2_dir=LEFT1;
                break;

        case 2:
        case 4:

                ghost2_dir=RIGHT1;
                break;

        }

        ghost22=ghost2;
    }


void ghost1_move(enum ghost_move g1_dir)
{

  int x,y;
  if(g1_dir==UP1)
  {

      if(grid[ghost1_r-1][ghost1_c]!= '*')
      {
          grid[ghost1_r][ghost1_c]=' ';
          grid[ghost1_r-1][ghost1_c]='&';
          ghost1_r--;

          if(grid[ghost1_r][ghost1_c]==grid[1][12]||grid[ghost1_r][ghost1_c]==grid[1][24]||grid[ghost1_r][ghost1_c] == grid[1][43])
          {
              x=rand()%2;
                switch (x)
                {
                case 0:

                        ghost1_dir = LEFT1;
                         break;


                case 1:

                        ghost1_dir = RIGHT1;
                        break;


                }
          }


          else if(grid[ghost1_r][ghost1_c]==grid[8][3])
            {
                x=rand()%2;
                switch (x)
                {
                case 0:
                    break;
                case 1:

                        ghost1_dir = RIGHT1;
                    break;


                }
            }
         else if(grid[ghost1_r][ghost1_c]==grid[1][3])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:

                        ghost1_dir = RIGHT1;
                    break;


                case 1:

                        ghost1_dir = DOWN1;
                    break;


            }
         }
         else if(grid[ghost1_r][ghost1_c]==grid[8][68])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:
                    break;
                case 1:

                        ghost1_dir = LEFT1;
                    break;


            }
         }
         else if(grid[ghost1_r][ghost1_c]==grid[1][68])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:

                        ghost1_dir = LEFT1;
                    break;


                case 1:

                        ghost1_dir = DOWN1;
                    break;


            }
         }
         else if(grid[ghost1_r][ghost1_c]==grid[8][33])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:

                        ghost1_dir = LEFT1;
                    break;


                case 1:

                        ghost1_dir = RIGHT1;
                    break;


            }

         }

    }
  }
  else if (g1_dir==DOWN1)
  {
      if(grid[ghost1_r+1][ghost1_c]!= '*')
      {
          grid[ghost1_r][ghost1_c]=' ';
          grid[ghost1_r+1][ghost1_c]='&';
          ghost1_r++;

           if(grid[ghost1_r][ghost1_c]==grid[8][12]||grid[ghost1_r][ghost1_c]
              ==grid[8][24]||grid[ghost1_r][ghost1_c]== grid[8][43]||grid[ghost1_r][ghost1_c] == grid[19][33])
           {
               x=rand()%2;
            switch (x)
            {
                case 0:

                        ghost1_dir = LEFT1;
                    break;


                case 1:

                        ghost1_dir = RIGHT1;
                    break;



            }
           }


           else if(grid[ghost1_r][ghost1_c]==grid[8][3])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:
                    break;
                case 1:

                        ghost1_dir = RIGHT1;
                    break;


            }
         }
         else if(grid[ghost1_r][ghost1_c]==grid[19][3])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:

                        ghost1_dir = RIGHT1;
                    break;


                case 1:

                        ghost1_dir = UP1;
                    break;


            }
         }
         else if(grid[ghost1_r][ghost1_c]==grid[8][68])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:
                    break;
                case 1:

                        ghost1_dir = LEFT1;
                    break;


            }
         }
         else if(grid[ghost1_r][ghost1_c]==grid[19][68])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:

                        ghost1_dir = LEFT1;
                    break;


                case 1:

                        ghost1_dir = UP1;
                    break;


            }
         }
      }

  }
  if(g1_dir==LEFT1)
  {

      if(grid[ghost1_r][ghost1_c-1]!= '*')
      {
          grid[ghost1_r][ghost1_c]=' ';
          grid[ghost1_r][ghost1_c-1]='&';
          ghost1_c--;
          if(grid[ghost1_r][ghost1_c]==grid[1][12]||grid[ghost1_r][ghost1_c]==grid[1][24]||grid[ghost1_r][ghost1_c] == grid[1][43])
          {
              x=rand()%2;
            switch (x)
            {
                case 0:
                    break;
                case 1:
                    {
                        ghost1_dir = DOWN1;
                    break;
                    }

            }
          }
          else if(grid[ghost1_r][ghost1_c]==grid[8][12]||grid[ghost1_r][ghost1_c]==grid[8][24]||grid[ghost1_r][ghost1_c] == grid[8][43])
          {
             x=rand()%2;
            switch (x)
            {
                case 0:
                    break;
                case 1:
                    {
                        ghost1_dir = UP1;
                    break;
                    }

            }
          }
         else if(grid[ghost1_r][ghost1_c]==grid[8][33])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:
                    break;
                case 1:
                    {
                        ghost1_dir = DOWN1;
                    break;
                    }

            }
         }
         else if(grid[ghost1_r][ghost1_c]==grid[1][3])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:
                    {
                        ghost1_dir = RIGHT1;
                    break;
                    }

                case 1:
                    {
                        ghost1_dir = DOWN1;
                    break;
                    }

            }
         }
         else if(grid[ghost1_r][ghost1_c]==grid[8][3])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:
                    {
                        ghost1_dir = UP1;
                    break;
                    }

                case 1:
                    {
                        ghost1_dir = DOWN1;
                    break;
                    }

            }
         }
         else if(grid[ghost1_r][ghost1_c]==grid[19][3])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:
                    {
                        ghost1_dir = UP1;
                    break;
                    }

                case 1:
                    {
                        ghost1_dir = RIGHT1;
                    break;
                    }

            }
         }

      }


  }
  else if (g1_dir==RIGHT1)
  {
      if(grid[ghost1_r][ghost1_c+1]!= '*')
      {
          grid[ghost1_r][ghost1_c]=' ';
          grid[ghost1_r][ghost1_c+1]='&';
          ghost1_c++;

          if(grid[ghost1_r][ghost1_c]==grid[1][12]||grid[ghost1_r][ghost1_c]==grid[1][24]||grid[ghost1_r][ghost1_c] == grid[1][43])
          {

            x=rand()%2;
            switch (x)
            {
                case 0:
                    break;
                case 1:
                    {
                        ghost1_dir = DOWN1;
                    break;
                    }

            }
          }
          else if(grid[ghost1_r][ghost1_c]==grid[8][12]||grid[ghost1_r][ghost1_c]==grid[8][24]||grid[ghost1_r][ghost1_c] == grid[8][43])
          {
             x=rand()%2;
            switch (x)
            {
                case 0:
                    break;
                case 1:
                    {
                        ghost1_dir = UP1;
                    break;
                    }

            }
          }
          else if(grid[ghost1_r][ghost1_c]==grid[8][33])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:
                    break;
                case 1:
                    {
                        ghost1_dir = DOWN1;
                    break;
                    }

            }
         }
         else if(grid[ghost1_r][ghost1_c]==grid[1][68])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:
                    {
                        ghost1_dir = LEFT1;
                    break;
                    }

                case 1:
                    {
                        ghost1_dir = DOWN;
                    break;
                    }

            }
         }
         else if(grid[ghost1_r][ghost1_c]==grid[8][68])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:
                    {
                        ghost1_dir = UP1;
                    break;
                    }

                case 1:
                    {
                        ghost1_dir = DOWN1;
                    break;
                    }

            }
         }
         else if(grid[ghost1_r][ghost1_c]==grid[19][68])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:
                    {
                        ghost1_dir = UP1;
                    break;
                    }

                case 1:
                    {
                        ghost1_dir = LEFT1;
                    break;
                    }

            }
         }
      }

  }
}
void ghost2_move(enum ghost_move g2_dir)
{

    int x,y;

    if(g2_dir==LEFT1)
    {

        if(grid[ghost2_r][ghost2_c-1]!= '*')
        {
          grid[ghost2_r][ghost2_c]=' ';
          grid[ghost2_r][ghost2_c-1]='@';
          ghost2_c--;

            if(grid[ghost2_r][ghost2_c]==grid[19][33])
            {
              x=rand()%2;
              if(x==0||x==1)
                switch (x)
                {
                    case 0:
                    break;
                    case 1:
                    {
                        ghost2_dir = DOWN1;
                    break;
                    }

                }
           }
            else if(grid[ghost2_r][ghost2_c]==grid[19][3])
            {
                 x=rand()%2;
                 if(x==0||x==1)
                switch (x)
                {
                    case 0:
                        {
                            ghost2_dir= UP1;
                        break;
                        }

                    case 1:
                        {
                        ghost2_dir = RIGHT1;
                        break;
                        }

                }
            }
            if(grid[ghost2_r][ghost2_c]==grid[8][43]||grid[ghost2_r][ghost2_c]==grid[8][24]||grid[ghost2_r][ghost2_c]==grid[8][12])
            {
                x=rand()%2;
                if(x==0||x==1)
                switch (x)
              {
                case 0:
                    break;
                case 1:
                    {
                        ghost2_dir = UP1;
                    break;
                    }

              }
            }
           else if(grid[ghost2_r][ghost2_c]==grid[8][33])
           {
               x=rand()%2;
               if(x==0||x==1)
                switch (x)
              {
                case 0:
                    break;
                case 1:
                    {
                        ghost2_dir = DOWN1;
                    break;
                    }
              }

           }
           if(grid[ghost2_r][ghost2_c]==grid[1][3])
           {
               x=rand()%2;
               if(x==0||x==1)
                switch (x)
              {
                case 0:
                    {
                        ghost2_dir = RIGHT1;
                        break;
                    }

                case 1:
                    {
                        ghost2_dir = DOWN1;
                    break;
                    }
             }
          }
          else if(grid[ghost2_r][ghost2_c]==grid[1][12]||grid[ghost2_r][ghost2_c]==grid[1][24]||grid[ghost2_r][ghost2_c]==grid[1][43])
          {
              x=rand()%2;
              if(x==0||x==1)
                switch (x)
              {
                case 0:
                    {
                        ghost2_dir=LEFT1;
                        break;
                    }

                case 1:
                    {
                        ghost2_dir = DOWN1;
                        break;
                    }
             }
          }
        }
    }
      if (g2_dir==RIGHT1)
        {
            if(grid[ghost2_r][ghost2_c+1]!= '*')
            {
                grid[ghost2_r][ghost2_c+1]='@';
                grid[ghost2_r][ghost2_c]=' ';
                ghost2_c++;


                if(grid[ghost2_r][ghost2_c]==grid[19][33])
                {
                    x=rand()%2;
                    if(x==0||x==1)
                    switch (x)
                    {
                        case 0:
                        break;
                        case 1:
                        {
                            ghost2_dir = UP1;
                        break;
                        }

                    }
                }
               else if(grid[ghost2_r][ghost2_c]==grid[19][68])
                 {
                  x=rand()%2;
                  if(x==0||x==1)
                  switch (x)
                    {
                        case 0:
                        {
                            ghost2_dir = LEFT1;
                            break;
                        }
                        case 1:
                        {
                            ghost2_dir = UP1;
                            break;
                        }

                    }
                }
                if(grid[ghost2_r][ghost2_c]==grid[8][43]||grid[ghost2_r][ghost2_c]==grid[8][24]||grid[ghost2_r][ghost2_c]==grid[8][12])
                {


                   x=rand()%2;
                   if(x==0||x==1)
                  switch (x)
                    {
                        case 0:
                        {
                            break;
                        }
                        case 1:
                        {
                            ghost2_dir = UP1;
                            break;
                        }

                    }
                }
                else if(grid[ghost2_r][ghost2_c]==grid[8][33])
                {
                    x=rand()%2;
                    if(x==0||x==1)
                  switch (x)
                    {
                        case 0:
                        {
                            break;
                        }
                        case 1:
                        {
                            ghost2_dir = DOWN1;
                            break;
                        }

                    }
                }
        }

     }
     if (g2_dir==UP1)
     {

             if(grid[ghost2_r-1][ghost2_c]!= '*')
            {
                grid[ghost2_r][ghost2_c]=' ';
                grid[ghost2_r-1][ghost2_c]='@';
                ghost2_r--;

                if(grid[ghost2_r][ghost2_c]==grid[8][3])
                {

                    x=rand()%2;
                    if(x==0||x==1)
                  switch (x)
                    {
                        case 0:
                        {
                            break;
                        }
                        case 1:
                        {
                            ghost2_dir = RIGHT1;
                            break;
                        }

                    }
                }
                else if (grid[ghost2_r][ghost2_c]==grid[8][68])
                {
                    x=rand()%2;
                  if(x==0||x==1)
                  switch (x)
                    {
                        case 0:
                        {
                            break;
                        }
                        case 1:
                        {
                            ghost2_dir = LEFT1;
                            break;
                        }

                    }
                }
                if(grid[ghost2_r][ghost2_c]==grid[8][33])
                {
                    x=rand()%2;
                    if(x==0||x==1)
                  switch (x)
                    {
                        case 0:
                        {
                            ghost2_dir= RIGHT1;
                            break;
                        }
                        case 1:
                        {
                            ghost2_dir = LEFT1;
                            break;
                        }

                    }
                }

                if(grid[ghost2_r][ghost2_c]==grid[1][12]||grid[ghost2_r][ghost2_c]==grid[1][24]||grid[ghost2_r][ghost2_c] == grid[1][43])
                {
                    x=rand()%2;
                    if(x==0||x==1)
                  switch (x)
                    {
                        case 0:
                        {
                            ghost2_dir= RIGHT1;
                            break;
                        }
                        case 1:
                        {
                            ghost2_dir = LEFT1;
                            break;
                        }

                    }
                }
                else if(grid[ghost2_r][ghost2_c]==grid[1][68])
                {
                    x=rand()%2;
                    if(x==0||x==1)
                  switch (x)
                    {
                        case 0:
                        {
                            ghost2_dir= DOWN1;
                            break;
                        }
                        case 1:
                        {
                            ghost2_dir = LEFT1;
                            break;
                        }

                    }
                }
                else if(grid[ghost2_r][ghost2_c]==grid[1][3])
                {
                    x=rand()%2;
                    if(x==0||x==1)
                  switch (x)
                    {
                        case 0:
                        {
                            ghost2_dir= DOWN1;
                            break;
                        }
                        case 1:
                        {
                            ghost2_dir = RIGHT1;
                            break;
                        }
                    }
                }
        }
     }
     if (g2_dir==DOWN1)
     {
         if(grid[ghost2_r+1][ghost2_c]!= '*')
      {
          grid[ghost2_r][ghost2_c]=' ';
          grid[ghost2_r+1][ghost2_c]='@';
          ghost2_r++;

           if(grid[ghost2_r][ghost2_c]==grid[8][3])
           {
                x=rand()%2;
                if(x==0||x==1)
               switch (x)
              {
                case 0:
                    {

                    break;
                    }

                case 1:
                    {
                        ghost2_dir = RIGHT1;
                    break;
                    }
              }


           }
           else if(grid[ghost2_r][ghost2_c]==grid[8][12])
           {
             x=rand()%2;
             if(x==0||x==1)
               switch (x)
              {
                case 0:
                    {
                       ghost2_dir = RIGHT1;
                       break;
                    }

                case 1:
                    {
                        ghost2_dir = RIGHT1;
                        break;
                    }
              }
           }
          else if(grid[ghost2_r][ghost2_c]==grid[8][43])
            {
                     x=rand()%2;
                     if(x==0||x==1)
                    switch (x)
                    {
                        case 0:
                            {
                                ghost2_dir = RIGHT1;
                                break;
                            }

                        case 1:
                            {
                                ghost2_dir = RIGHT1;
                                break;
                            }
                    }
            }
       }
     }
}


