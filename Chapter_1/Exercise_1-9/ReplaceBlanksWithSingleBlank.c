#include <stdio.h>

main()
{
    int c;
    bool blankDetected = 0;

    while ((c = getchar()) != EOF)
    {

        while (c == ' ')        //keep looping through all the blanks
        {
            blankDetected = 1;  //set our flag
            c = getchar();
        }
        
        if (blankDetected)      //we know we had at least one blank
        {
            blankDetected = 0;  //reset our flag
            putchar(' ');       //place our one blank
            putchar(c);         //c should not be a blank since we broke out of our while above
        }
        else
        {
            putchar(c);         //no blanks, just copy input
        }
    }
}
