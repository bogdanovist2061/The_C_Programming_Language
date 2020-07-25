/* 
 * After much consternation, I figured out the backspace key
 * on a Linux machine does not map to the same character
 * as on a Unix machine.
 *
 * In Unix, the backspace key maps to '^H', but on my
 * Linux machine, this key produces '^?'. Thus, initially
 * the program was not finding my typed backspaces, which
 * took a bit of digging to figure out.
 *
 * After some research, I discovered the terminal
 * itself was processing the backspaces before
 * they had a chance to enter the program. Enter the
 * termios man page! As well as an old Unix programming
 * book I had lying around ^..^
 *
 * This program disables processing of the backspace
 * key using the termios struct and its attribute flags.
 * Running this program, you'll see '^?' characters
 * when you type the backspace key. (This is what led
 * me to the realization that my backspace key was
 * not producing the '^H' character as expected.
 * In order to get this character on a Linux system,
 * type CTRL+Backspace.)
 *
 * But how do we tell our program to search for this
 * carat-question mark character? Running the
 * 'showkey' program with the -a parameter will allow
 * you to type any key and see its hexadecimal value.
 * Typing Backspace gives a hex value of 0x7f. Thus,
 * in our program we can check directly if any of
 * our chars match the value 0x7f.
 *
 * Now our program will find Linux backspaces, too!
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

main ()
{
    struct termios originalTerm;
    struct termios term;
    long vdisable;    
    int c;
    
    //Get system vdisable value
    vdisable = fpathconf(STDIN_FILENO, _PC_VDISABLE);
    
    //Make a copy of our original terminal attributes
    tcgetattr(STDIN_FILENO, &originalTerm);

    //Get current terminal attributes so we can modify
    tcgetattr(STDIN_FILENO, &term);

    //Use the c_cc array in the termios stucture to
    //set the backspace flag to disabled
    term.c_cc[VERASE] = vdisable;

    //Set our new terminal attributes
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &term);

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
        else if (c == 0x7F)
        {
            putchar('\\');
            putchar('b');
            
        }
        else
        {
            putchar(c);
        }
    }

    //Set our terminal attributes back to original
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &originalTerm);
}
