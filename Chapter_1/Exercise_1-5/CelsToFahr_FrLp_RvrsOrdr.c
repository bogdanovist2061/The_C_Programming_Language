#include <stdio.h>

main()
{
    int fahr;

    //Print heading
    printf("%10s   %7s\n", "Fahrenheit", "Celsius");

    for (fahr = 300; fahr >= 0; fahr -= 20) 
    {
        printf("%10d   %7.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
    }
}
