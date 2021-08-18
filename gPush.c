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
 int checkInstallation(void);
 void gotoxy(int,int);
 void Exitfn(void);


 /**********************main function***************************/
 int main ()
 {

    if(_typeOS)
    {
        SetConsoleTitle("Git Pusher");
        MenuBar();


    }else
    {

        printf("Sorry this application is not supported in Linux or its versions\n Only for Windows Operating System..");

        getch();
    }

    return 0;


 }


/***************************************/
//functions

//menu bar function
void MenuBar()
{

    int gitInstalled;

    //first we will check either git is installed in our machine or not
    gitInstalled = checkInstallation();

    if(gitInstalled)
    {
        printf("Hello");

    }else
    {
        //if git is not installed in machine we will choice to user for download
        char choice;

        system("cls");
        gotoxy(40,12);
        system("color 0a");
        printf("Git is not installed in your machine.");
        gotoxy(40,14);
        printf("1 : Download Git");
         gotoxy(61,14);
        printf("2 : Exit");

        readAgain:
        gotoxy(40,15);
        choice = getch();

        if(choice == '1')
        {
            system("start https://git-scm.com/downloads");
            exit(0);
        }else if(choice == '2')
        {
            Exitfn();

        }else
        {
            printf("\a");
            goto readAgain;
        }

    }



}



//git installed status
int checkInstallation()
{
   //this function will check that git is installed or not
   int status;

   status = system("git --version");

    return status;


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

//Exit function..
void Exitfn()
{
    gotoxy(40,12);
    system("cls");
    gotoxy(40,12);
    printf("Thanx for visiting us");
    getch();
    exit(0);
}
