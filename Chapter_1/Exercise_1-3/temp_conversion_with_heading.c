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
    printf("%10s   %7s\n", "Fahrenheit", "Celsius");

    fahr = lower;
    while (fahr <= upper) {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%10.0f   %7.1f\n", fahr, celsius);
        fahr += step;
    }
}
