/*
 * In order to type the Backspace
 * character (\b) on a Linux system,
 * type CTRL+Backspace.
 * 
 * */

#include <stdio.h>

main ()
{
    int c;
    
    while ((c = getchar()) != EOF)
    {   
        if (c == '\t')
        {
            putchar('\\');
            putchar('t');
        }
        else if (c == '\b') 
        {
            putchar('\\');
            putchar('b');
        }
        else if (c == '\\')
        {
            putchar('\\');
            putchar('\\');
        }
        else
        {
            putchar(c);
        }
    }
}
