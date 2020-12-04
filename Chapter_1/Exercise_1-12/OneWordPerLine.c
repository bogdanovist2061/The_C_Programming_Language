#include <stdio.h>

#define INSIDE_WORD     1
#define OUTSIDE_WORD    0

main()
{
    int c = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            putchar('\n');
        }
        else
        {
            putchar(c);
        }
    }
}
