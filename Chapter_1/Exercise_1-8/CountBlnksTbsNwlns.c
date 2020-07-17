#include <stdio.h>

main()
{
    int c;
    long blanks = 0;
    long tabs = 0;
    long newlines = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            blanks++;
        }
        else if (c == '\t')
        {
            tabs++;
        }
        else if (c == '\n')
        {
            newlines++;
        }
    }

    printf("blanks: %ld\n", blanks);
    printf("tabs: %ld\n", tabs);
    printf("newlines: %ld\n", newlines);
}
