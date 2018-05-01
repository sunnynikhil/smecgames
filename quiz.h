
#include<stdio.h>
#include<conio.h>
#include <windows.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
#include<dos.h>
char nameq[15];
void recordquiz(float);
void displayscore(void);
void writescore(float,char[]);
void recordquiz(float score){
   char nplname[20],cha,c;
   int i,j,px;
   FILE *info;
   info=fopen("recordqui.txt","a+");
   getch();
   system("cls");
   printf("Enter your name\n");
   scanf("%[^\n]",nameq);
   for(j=0;nameq[j]!='\0';j++){
   nplname[0]=toupper(nameq[0]);
   if(nameq[j-1]==' '){
   nplname[j]=toupper(nameq[j]);
   nplname[j-1]=nameq[j-1];}
   else nplname[j]=nameq[j];
   }
   nplname[j]='\0';
   fprintf(info,"player Name :%s\n",nplname);
   time_t mytime;
  mytime = time(NULL);
  fprintf(info," Date:%s",ctime(&mytime));
     fprintf(info,"score:%.2f\n",score);
   for(i=0;i<=50;i++)
   fprintf(info,"%c",'_');
   fprintf(info,"\n");
   fclose(info);
   writescore(score,nameq);
   printf("wanna see past records press 'y'\n");
   cha=getch();
   system("cls");
   if(cha=='y'){
   info=fopen("recordqui.txt","r");
   do{
       putchar(c=getc(info));
       }while(c!=EOF);
       }
     fclose(info);
     getch();
}
void recordfile()
{char c;
   FILE *f;
   f=fopen("recordqui.txt","r");
   do{
    putchar(c=getc(f));
   }
   while(c!=EOF);

    fclose(f);
    getch();
}
void displayscore()
 {
 char name[20];
 float s;
 FILE *f;
 system("cls");
 f=fopen("score.txt","r");
 fscanf(f,"%s%f",&name,&s);
 printf("\n\n\t\t ");
 printf("\n\n\t\t %s has secured the Highest Score %.2f",name,s);
 printf("\n\n\t\t ");
 fclose(f);
 getch();
 }
 void writescore(float score,char pln[20])
 {

 float sc;
 char nm[20];
 FILE *f;
 system("cls");
 f=fopen("score.txt","r");
 fscanf(f,"%s%f",&nm,&sc);
 if (score>=sc)
   { sc=score;
     fclose(f);
     f=fopen("score.txt","w");
     fprintf(f,"%s\n%.2f",pln,sc);
     fclose(f);
   }
 }
void help()
 {
 system("cls");
 printf("\n\n\n\tThis game is very easy to play. You'll be asked some general");
 printf("\n\n\tcoding questions and the right answer is to be chosen among");
 printf("\n\n\tthe four options provided. Your score will be calculated at the");
 printf("\n\n\tend. Remember that the more quicker you give answer the more");
 printf("\n\n\tscore you will secure. Your score will be calculated and displayed");
 printf("\n\n\tat the end and displayed. If you secure highest score, your score");
 printf("\n\n\twill be recorded. So BEST OF LUCK.HAPPY CODING");
 }

void quiz()
     {
     int countq,countr;
     int r,i;
     int pa;int nq[6];int w;
     float score;
     char choice;
     char playername[20];
     time_t initialtime,finaltime;
     system("cls");
     mainhome:
     system("cls");
     puts("\n\t\t WELCOME TO CODING TEST PROGRAM\n\n") ;
     puts("\n\t\t-------------------------------");
     puts("\n\t\t Enter 'S' to start game       ");
     puts("\n\t\t Enter 'V' to view records  ");
     puts("\n\t\t Enter 'H' for help            ");
     puts("\n\t\t Enter 'Q' to quit             ");
     printf("\n\t\t-------------------------------\n\n\t\t  ");
     choice=toupper(getch());
     if (choice=='V')
 {
 recordfile();
 goto mainhome;
 }
     else if (choice=='Q')
     {

     printf("HAPPY CODING\n");
 exit(1);
     }
     else if (choice=='H')
 {
 help();
 getch();
 goto mainhome;
 }
    else if(choice=='S'){
     system("cls");

     printf("\n\n\n\t\t\tEnter your name...");
     printf("\n\t\t\t(only one word)\n\n\t\t\t");
     gets(playername);

     home:
     system("cls");
     initialtime=time(NULL);
     countq=countr=0;
     i=1;
     start:
     srand ( time(NULL) );
     r=rand()%23+1;
     nq[i]=r;
     for (w=0;w<i;w++)
 if (nq[w]==r) goto start;
     switch(r)
  {
  case 1:
      printf("\n#include");
printf("\nwhich of the followings is correct for a function definition along with storage-class specifier in C language?\n\nA.int fun(auto int arg)\n\nB.int fun(static int arg)\n\nC.int fun(register int arg)\n\nD.int fun(extern int arg)");
  countq++;
  if (toupper(getch())=='C')
   {printf("\n\nCorrect!!!");countr++; break;}
  else
         {printf("\n\nWrong!!! The correct answer is C.C.int fun(register int arg)");break;
         }

  case 2:
  printf("\n\n\nPick the best statement for these.\n\nA.All of the above variable definitions are incorrect because basic data type int is missing.\n\nB.All of the above variable definitions are correct because int is implicitly assumed in all of these.\n\nC.Only “long l;” and “long long ll;” are valid definitions of variables.\n\nD.Only “unsigned u;” is valid definition of variable.");
  countq++;
  if (toupper(getch())=='B')
   {printf("\n\nCorrect!!!");countr++; break;}
  else
         printf("\n\nWrong!!! The correct answer is B.All of the above variable definitions are correct because int is implicitly assumed in all of these.");
  break;

  case 3:
  printf("\n\n\nPick the correct statement for const and volatile.\n\nA.const is the opposite of volatile and vice versa.\n\nB.const and volatile can’t be used for struct and union.\n\nC.const and volatile can’t be used for enum.\n\nD.const and volatile are independent i.e. it’s possible that a variable is defined as both const and volatile.");
  countq++;
  if (toupper(getch())=='D')
   {printf("\n\nCorrect!!!");countr++; break;}
  else
         {printf("\n\nWrong!!! The correct answer is D.const and volatile are independent i.e. it’s possible that a variable is defined as both const and volatile.");break;}


  case 4:
  printf("\n\n\nWhich of the following statement is correct for switch controlling expression?\n\nA.Only int can be used in “switch” control expression.\n\nB.Both int and char can be used in “switch” control expression.\n\nC.All types i.e. int, char and float can be used in “switch” control expression.\n\nD.“switch” control expression can be empty as well.");
  countq++;
  if (toupper(getch())=='A')
   {printf("\n\nCorrect!!!");countr++; break;}
  else
         {printf("\n\nWrong!!! The correct answer is B.Both int and char can be used in “switch” control expression.");break;}


  case 5:
  printf("\n\n\nWhat’s the size returned for each of sizeof() operator?\n\nA.4 4 4\n\nB.1 4 4\n\nC.1 4 8\n\nD.None of the above");
  countq++;
  if (toupper(getch())=='A')
   {printf("\n\nCorrect!!!");countr++; break;}
  else
         {printf("\n\nWrong!!! The correct answer is A.4 4 4");break;}

  case 6:
  printf("\n\n\nIn the context of C data types, which of the followings is correct?\n\nA.“unsigned long long int” is a valid data type.\n\nB.“long long double” is a valid data type.\n\nC.“unsigned long double” is a valid data type.\n\nD.A), B) and C) all are valid data types.");
  countq++;
  if (toupper(getch())=='A' )
   {printf("\n\nCorrect!!!");countr++; break;}
  else
         {printf("\n\nWrong!!! The correct answer is A.“unsigned long long int” is a valid data type");break;}


  case 7:
  printf("\n\n\nSuppose a C program has floating constant 1.414, what's the best way to convert this as float data type?\n\nA.(float)1.414\n\nB.float(1.414)\n\nC.1.414f or 1.414F\n\nD.1.414 itself of float data type i.e. nothing else required.");
  countq++;
  if (toupper(getch())=='C')
   {printf("\n\nCorrect!!!");countr++; break;}
  else
         {printf("\n\nWrong!!! The correct answer is C.1.414f or 1.414F");break;}


  case 8:
  printf("\n\n\nFor a given integer, which of the following operators can be used to “set” and “reset” a particular bit respectively?\n\nA.| and &\n\nB.&& and ||\n\nC.& and |\n\nD.|| and &&");
  countq++;
  if (toupper(getch())=='A')
   {printf("\n\nCorrect!!!");countr++; break;}
  else
         {printf("\n\nWrong!!! The correct answer is A.| and &");break;}


  case 9:
  printf("\n\n\nWhich of the following functions from “stdio.h” can be used in place of printf()?\n\nA.fputs() with FILE stream as stdout.\n\nB.fprintf() with FILE stream as stdout.\n\nC.fwrite() with FILE stream as stdout.\n\nD.All of the above three - a, b and c.");
  countq++;
  if (toupper(getch())=='B')
   {printf("\n\nCorrect!!!");countr++; break;}
  else
         {printf("\n\nWrong!!! The correct answer is B.fprintf() with FILE stream as stdout");break;}


  case 10:
  printf("\n\n\nAs per C language standard, which of the followings is/are not keyword(s)? Pick the best statement. auto make main sizeof elseif\n\nA.None of the above is keywords in C.\n\nB.make main elseif\n\nC.make main\n\nD.auto make");
  countq++;
  if (toupper(getch())=='B')
   {printf("\n\nCorrect!!!");countr++; break;}
  else
         {printf("\n\nWrong!!! The correct answer is B.make main elseif");break;}


  case 11:
  printf("\n\n\nIn the context of break and continue statements in C, pick the best statement.\n\nA.break can be used in for, while and do-while loop body.\n\nB.continue can be used in for, while and do-while loop body.\n\nC.break and continue can be used in for, while, do-while loop body and switch body.\n\nD.break and continue can be used in for, while and do-while loop body. But only break can be used in switch body.");
  countq++;
  if (toupper(getch())=='D')
   {printf("\n\nCorrect!!!");countr++; break;}
  else
         {printf("\n\nWrong!!! The correct answer is D.“break” and continue can be used in for, while and do-while loop body. But only break can be used in switch body.");break;}

  case 12:
  printf("\n\n\nWhich of the following is correct with respect to “Jump Statements” in C?\n\nA.goto\n\nB.continue\n\nC.break\n\nD.All of the above.");
   countq++;
  if (toupper(getch())=='D')
   {printf("\n\nCorrect!!!");countr++; break;}
  else
         {printf("\n\nWrong!!! The correct answer is D.All of the above");break;}

  case 13:
printf("\n\n\n“typedef” in C basically works as an alias. Which of the following is correct for “typedef”?\n\nA.typedef can be used to alias compound data types such as struct and union.\n\nB.typedef can be used to alias both compound data types and pointer to these compound types.\n\nC.typedef can be used to alias a function pointer.\n\nD.All of the above.");
  countq++;
  if (toupper(getch())=='D')
   {printf("\n\nCorrect!!!");countr++; break;}
  else
         {printf("\n\nWrong!!! The correct answer is D.All of the above");break;}

  case 14:
  printf("\n\n\nWhich of the following true about FILE *fp\n\nA.FILE is a keyword in C for representing files and fp is a variable of FILE type.\n\nB.FILE is a structure and fp is a pointer to the structure of FILE type\n\nC.FILE is a stream\n\nD.FILE is a buffered stream");
  countq++;
  if (toupper(getch())=='B')
   {printf("\n\nCorrect!!!");countr++; break;}
  else
         {printf("\n\nWrong!!! The correct answer is B.FILE is a structure and fp is a pointer to the structure of FILE type");break;}

  case 15:
  printf("\n\n\ngetc() returns EOF when\n\nA.End of files is reached\n\nB.When getc() fails to read a character\n\nC.Both of the above\n\nD.None of the above");
  countq++;
  if (toupper(getch())=='C')
   {printf("\n\nCorrect!!!");countr++; break;}
  else
         {printf("\n\nWrong!!! The correct answer is C.Both of the above");break;}

  case 16:
  printf("\n\n\nfseek() should be preferred over rewind() mainly because\n\nA.rewind() doesn't work for empty files\n\nB.rewind() may fail for large files\n\nC.In rewind, there is no way to check if the operations completed successfully\n\nD.All of the above");
  countq++;
  if (toupper(getch())=='C')
   {printf("\n\nCorrect!!!");countr++; break;}
  else
         {printf("\n\nWrong!!! The correct answer is C.In rewind, there is no way to check if the operations completed successfully");break;}


  case 17:
  printf("\n\n\nWhen fopen() is not able to open a file, it returns\n\nA.EOF\n\nB.NULL\n\nC.Runtime Error\n\nD.Compiler Dependent");
  countq++;
  if (toupper(getch())=='B')
   {printf("\n\nCorrect!!!");countr++; break;}
  else
         {printf("\n\nWrong!!! The correct answer is B.NULL");break;}

  case 18:
  printf("\n\n\nIn C, parameters are always\n\nA.Passed by value\n\nB.Passed by reference\n\nC.Non-pointer variables are passed by value and pointers are passed by reference\n\nD.Passed by value result");
  countq++;
  if (toupper(getch())=='A')
   {printf("\n\nCorrect!!!");countr++; break;}
  else
         {printf("\n\nWrong!!! The correct answer is A.Passed by value");break;}

  case 19:
  printf("\n\n\nWhich of the following is true about return type of functions in C?\n\nA.Functions can return any type\n\nB.Functions can return any type except array and functions\n\nC.Functions can return any type except array, functions and union\n\nD.Functions can return any type except array, functions, function pointer and union");
  countq++;
  if (toupper(getch())=='B')
   {printf("\n\nCorrect!!!");countr++; break;}
  else
         {printf("\n\nWrong!!! The correct answer is B.Functions can return any type except array and functions");break;}

  case 20:
  printf("\n\n\nWhich of the following is true\nA.gets() can read a string with newline chacters but a normal scanf() with %s can not.\n\nB.gets() can read a string with spaces but a normal scanf() with %s can not.\n\nC.gets() can always replace scanf() without any additional code.\n\nD.None of the above");
  countq++;
  if (toupper(getch())=='B')
   {printf("\n\nCorrect!!!");countr++; break;}
  else
         {printf("\n\nWrong!!! The correct answer is B.gets() can read a string with spaces but a normal scanf() with %s can not");break;}

  }
 i++;
 if (i<=5) goto start;
 finaltime=time(NULL);
 score=(float)countr/countq*100-difftime(finaltime,initialtime)/3;
 if (score<0) score=0;
 printf("\n\n\nYour Score: %.2f",score);
 if (score==100) printf("\n\nEXCELLENT!!! KEEP IT UP");
 else if (score>=80 && score<100) printf("\n\nVERY GOOD!!");
 else if (score>=60 &&score<80) printf("\n\nGOOD! BUT YOU NEED TO KNOW MORE.");
 else if (score>=40 && score<60) printf("\n\nSATISFACTORY RESULT, BUT THIS MUCH IS MUCH SUFFICIENT.");
 else printf("\n\nYOU ARE VERY POOR IN coding,WORK HARD");
 recordquiz(score);
 }
     else
 {
 printf("\n\n\t\t  Enter the right key\n\n\t\t  ");
 Sleep(700);
 goto mainhome;
 }
 initializegame();
}
