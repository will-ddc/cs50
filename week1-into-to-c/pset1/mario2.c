#include <stdio.h>
#include <cs50.h>

int get_block_count(void);

int main(void)
{
    int columns = get_block_count();

    // nested loop to print spaces and then a # based on number of columns to create right hand side pyramid

    for (int i = 1; i <= columns; i++)
    {
        for (int d = 0; d < columns - i; d++)
        {
            printf(" ");
        }
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }
        printf("  ");
        for (int l = 0; l < i; l++)
        {
            printf("#");
        }
        printf("\n");
    }
}

// function to get block build height between 1 and 8

int get_block_count(void)
{
    int b;
    do
    {
        b = get_int("Input Height: ");
    }
    while (b <= 0 || b >= 9);
    return b;
}
