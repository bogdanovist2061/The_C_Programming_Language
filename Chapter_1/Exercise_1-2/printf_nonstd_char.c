#include <stdio.h>

main()
{
    printf("hello, world\c");
}

/*The above program yields the following compiler error:
 * printf_nonstd_char.c: In function ‘int main()’:
 * printf_nonstd_char.c:5:12: warning: unknown escape sequence: '\c'
 *      printf("hello, world\c");
 *
 * */
