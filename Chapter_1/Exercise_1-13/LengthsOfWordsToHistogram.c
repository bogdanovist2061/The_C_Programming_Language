#include <stdio.h>

main()
{
    int c;
    int LongestWordLength = 0;
    int WordLengths[20];
    int WordLengthsIndex = 0;
    int wc = 0;

    for (int i = 0; i < 20; i++)
    {
        WordLengths[i] = 0;
    }
    
    while ((c = getchar()) != EOF)
    {   
        if (c == ' ' || c == '\n' || c == '\t')
        {
            wc++;
            WordLengthsIndex++;
        }
        else
        {
            WordLengths[WordLengthsIndex]++;
        }
    }

    //Find longest word
    for (int i = 0; i < wc; i++)
    {
        if (WordLengths[i] > LongestWordLength)
        {
            LongestWordLength = WordLengths[i];
        }
    }

    for (int i = 0; i < LongestWordLength; i++) //Number of rows equal to longest word
    {        
        for (int j = 0; j < wc; j++) //Number of columns equal to number of words
        {
            if ((LongestWordLength - WordLengths[j]) > i)
            {
                printf("   ");
            }
            else
            {
                printf("[x]");
            }
        }
        printf("\n");
    }
    printf("\n");
}
