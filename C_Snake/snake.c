#include <stdio.h>

#define MIN_X 5
#define MIN_Y 4
#define SIZE_X 30
#define SIZE_Y 15
#define MAX_X (MIN_X + SIZE_X - 1)
#define MAX_Y (MIN_Y + SIZE_Y - 1)
#define NUM_POINTS (SIZE_X * SIZE_Y)

void refreshScreen(int score);

int main()
{
    char input;

    input = tolower(getch());

    while (input != 'x')
    {
        refreshScreen(5);
    }

    return 0;
}

void refreshScreen(int score)
{
    system("cls");
    for (int y = 0; y < MAX_Y; y++)
    {
        if (y == 1)
        {
            printf("Score: %d\n", score);
        }
        else if (y == 3 || y == MAX_Y - 1)
        {
            for (int x = 0; x < MAX_X; x++)
            {
                putchar('=');
            }
            putchar('\n');
        }
        else if (y > 3 && y < MAX_Y - 1)
        {
            for (int x = 0; x < MAX_X; x++)
            {
                if (x == 0 || x == MAX_X - 1)
                {
                    putchar('=');
                }
                else
                {
                    putchar(' ');
                }
            }
            putchar('\n');
        }
        else
            putchar('\n');
    }
}