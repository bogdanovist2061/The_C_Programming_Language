#include <stdio.h>

/*All possible keyboard inputs were given to this program. Each input,
 * yielded a '1', except of course ctrl+D (EOF on this PC) which
 * yielded a '0'.
 * 
 * */

main()
{
    while (true)
    {
        printf("Value of 'getchar() != EOF': %d\n", getchar() != EOF);
    }
}
