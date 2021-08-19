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
 void currentStatus(void);
 void CustomSetting(void);
 void gtDtail(char []);


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

    if(!gitInstalled)
    {
        //if git is installed we will show the menu
        ////////////////////////////////////
        char op;
        again1:
            again2:
        system("cls");

        system("color 0b");

        gotoxy(40,5);

        printf("1 : Current Status");

        gotoxy(40,7);

        printf("2 : Start Project");

        gotoxy(40,9);

        printf("3 : Give Contribution");

        gotoxy(40,11);

        printf("4 : Exit");

        readAg:

        op =getch();

        if(op == '1')
        {
            currentStatus();//after returning to this function it goes to main menu
            getch();

            goto again1;

        }else if(op == '2')
    {
        CustomSetting();
        getch();
        goto again2;


    }else if(op == '3')
    {
        system("start https://github.com/incredible-India/gitPusher");
        exit(0);

    }else if(op == '4')
    {

    Exitfn();

    }else{

     printf("\a");

     goto readAg;

    }
     /////////////////////////////

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

//for the custom settings
void CustomSetting()
{
    char *username = (char *) malloc(100*sizeof(char));
    char *useremail = (char *) malloc (100*sizeof(char));
    char *commit = (char *) malloc (200*sizeof(char));
    char *branch = (char *) malloc(30*sizeof(char));
    char *filepath = (char *) malloc(100*sizeof(char));

    system("cls");
    //first we will initlise the git

    system("git init");

    printf("\n Your Current path is\n\t");

    system("echo %cd%");

    gtDtail("path");


    gets(filepath);

    if(strlen(filepath) != 0)
    {
        system(filepath);
        free(filepath);
    }
    //checking for user name


     printf("\n Your Current User name is\n\t");

    system("git config --global user.name");

    gtDtail("User Name");


    gets(username);

    if(strlen(username) != 0)
    {
    //this will change the user name globally
        char gitCMD[] = "git config --global user.name ";
        char lcomma[100] = "\"";
        char rcomma[] = "\"";
       // char name[100] ;




      strcat(lcomma,strcat(username,rcomma));
      puts(lcomma);
      fflush(stdin);

       printf("%s",(strcat(gitCMD,lcomma)));

    free(username);

    }





}
//Current Status Of git

void currentStatus()
{
    system("cls");
    system("color 0d");
    printf("Git Version\n");
    system("git --version");

     printf("\nCurrent Path..\n");
    system("echo %cd%");

    printf("\nGlobal User Name\n");
    system("git config --global user.name");

    printf("\nGlobal User Email\n");
    system("git config --global user.email");

    printf("\nLocal User Name\n");
    system("git config user.name");

    printf("\nLocal User Email\n");
    system("git config user.email");



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

void gtDtail(char ch[])
{
    printf("\n Write %s or press \"Enter\" to continue..\n",ch);
    fflush(stdin);

}


