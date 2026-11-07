#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get pyradmid height from user
    int height;
    const int MIN_HEIGHT = 1;
    const int MAX_HEIGHT = 8;
    do
    {
        height = get_int("Height: ");
    } while (height < MIN_HEIGHT || height > MAX_HEIGHT);

    // Use leading spaces to right-align the rows
    int spaces = height - 1;

    for (int row = 0; row < height; row++)
    {
        // Print a right-aligned pyramid
        for (int col = 0; col < height; col++)
        {
            if (col < spaces)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }

        spaces -= 1;
        printf("  "); // Print the gap

        // Print a left-aligned pyramid
        for (int col = 0; col <= row; col++)
        {
            printf("#");
        }

        printf("\n");
    }

    return 0;
}
