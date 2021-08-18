/*Himanshu Sharma B.E 4th sem */

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

 //checking type of the operating system
 #ifdef _WIN32
 #define _typeOS 1
 #include<windows.h>
 #else
 #define _typeOS 0

 #endif

 //function declaration
 void MenuBar(void);

 int main ()
 {

    if(_typeOS)
    {

        MenuBar();


    }else
    {

        printf("Sorry this application is not supported in Linux or its versions\n Only for Windows Operating System..");

        getch();
    }

    return 0;


 }



//functions

//menu bar function
void MenuBar()
{

    printf("Hello World ");
}

//basic Functions
//for changing the co-ordinate  of console
void gotoxy(int xCord,int yCord)
{
    COORD x;
    x.X = xCord;
    x.Y = yCord;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),x);

}
