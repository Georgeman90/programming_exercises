#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_ATTEMPTS   3
#define USR_NAME_SIZE 50
#define PSW_SIZE      20

int attempts = MAX_ATTEMPTS;
bool exitBool = false;

void createAndWriteFile();
void login();
void exitCase();
bool isEmailValid(char *usr);
bool findInFile(char *usr, char *psw);

int main()
{
    char choice;

    puts("Welcome to a Login page!");

    while (!exitBool)
    {
        puts("Select one of the following services:");
        puts("1) Sign up,");
        puts("2) Sign in,");
        puts("3) Exit.");
        puts("Please enter your choice: ");
        choice = getch();
        
        switch (choice)
        {
        case '1':
            puts("1) Sign up service selected.");
            createAndWriteFile();
            puts("");
            break;
        case '2':
            puts("2) Sign in service selected.");
            login();
            puts("");
            break;
        case '3':
            exitCase();
            puts("");
            break;
        default:
            puts("Wrong choice! try again.");
            puts("");
            break;
        }
    }

    return 0;
}
//--------------------------------------------------------------------------------------------------
/*
*
*/
void exitCase()
{
    char exitChoice;

    puts("Do you really want to exit?(y/n)");
    exitChoice = tolower(getch()); // better this way
    if (exitChoice == 'y')
    {
        puts("Goodbye!");
        exitBool = true;
    }
}
//--------------------------------------------------------------------------------------------------
/*
*
*/
void login()
{
    int i = 0;
    char ch;
    char usr[USR_NAME_SIZE], psw[PSW_SIZE];

    puts("Insert your credential");
    printf("Username : ");
    scanf_s("%50s", usr, USR_NAME_SIZE);
    if (isEmailValid(usr))
    {
        printf("Password : ");
        // Password mask!: start
        while ((ch = getch()) != 13) // 13 = Carriage Return
        {
            psw[i] = ch;
            i++;
            printf("*");
        }
        puts("");
        psw[i] = '\0';
        // Password mask!: end

        if (findInFile(usr, psw))
            puts("Login successful");
        else
            printf("Failed to Login. You have %d remaining attempt.\n", --attempts);
    }
    else
    {
        puts("Wrong email format. Exiting sign in service...");
        printf("Failed to Login. You have %d remaining attempt.\n", --attempts);
    }
    //tmp
    if (attempts == 0)
    {
        puts("Goodbye!");
        exitBool = true;
    }
}
//--------------------------------------------------------------------------------------------------
/*
 * This function create, if it doesn't exist, or open a file in write mode.
 * Then, it will fill the created or opened file with user input couple username and password
 */
void createAndWriteFile()
{
    FILE *cfPtr;
    char usr[USR_NAME_SIZE], psw[PSW_SIZE];

    if ((cfPtr = fopen("clients.txt", "a")) == NULL) //#define NULL ((void *)0)
        puts("File could not be opened");
    else
    {
        puts("Enter the couple username and password.");
        printf("Username : ");
        scanf_s("%50s", usr, USR_NAME_SIZE);
        if (isEmailValid(usr))
        {
            printf("Password : ");
            scanf_s("%20s", psw, PSW_SIZE);

            fprintf(cfPtr, "%s %s\n", usr, psw);
        }
        else
        {
            puts("Wrong email format. Exiting insertion...");
        }
        fclose(cfPtr);
    }
}
//--------------------------------------------------------------------------------------------------
/*
 * This function open a file in read mode.
 * It will return true if the couple username/password searched is found, false otherwise.
 */
bool findInFile(char *usr, char *psw)
{
    bool result = false;
    FILE *cfPtr;    

    if ((cfPtr = fopen("clients.txt", "r")) == NULL)
        puts("File could not be opened");
    else
    {
        char tmp_usr[USR_NAME_SIZE], tmp_psw[PSW_SIZE];

        while (!feof(cfPtr)) //Da provare
        {
            fscanf(cfPtr, "%50s%20s", tmp_usr, tmp_psw);

            if (strcmp(usr, tmp_usr) == 0 && strcmp(psw, tmp_psw) == 0)
            {
                result = true;
                break;
            }
        }

        fclose(cfPtr);
    }

    return result;
}
//--------------------------------------------------------------------------------------------------
/*
 * This function returns true if the inserted email is valid, false otherwise.
 */
bool isEmailValid(char *usr)
{
    bool atFound = false;

    for (size_t i = 0; i < USR_NAME_SIZE; ++i)
    {
        if (usr[i] == '@')
            atFound = true;
    }

    return atFound;
}
//--------------------------------------------------------------------------------------------------