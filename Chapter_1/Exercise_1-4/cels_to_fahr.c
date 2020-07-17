#include <stdio.h>

main()
{
    float fahr;
    float celsius;
    int lower;
    int upper;
    int step;

    lower = 0;
    upper = 300;
    step = 20;

    //Print heading
    printf("%7s   %10s\n", "Celsius", "Fahrenheit");

    celsius = lower;
    while (celsius <= upper)
    {
        fahr = (9.0 / 5.0) * celsius + 32.0;
        printf("%7.0f   %10.1f\n", celsius, fahr);
        celsius += step;
    }
}
