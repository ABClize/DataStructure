#include <stdio.h>

int main()
{
    int m = 0, i, j;
    for (i = 1; i <= 3; i++)
    {
        for (j = 1; j <= 2 * i; j++)
        {
            m++;
        }
    }

    return 0;
}