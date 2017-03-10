/*Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring | cat -e
$
$>*/

#include <unistd.h>
#include <stdlib.h>
#define isspace(c) ( (c) == ' ' || (c) == '\t' )

void    rostring(char *str)
{
    int i;
    int start;
    int end;
    int word;


    i = 0;
    start = 0;
    end = 0;
    word = -1;
    
    while (str[i])
    {
        if (!isspace(str[i]) && str[i])
        {
            if (end == 0)
            {
                start = i;
                while (!isspace(str[i]) && str[i])
                    i++;
                end = i;
                break;
            }   
        }
        i++;
    }
    
    while (str[i])
    {   
        if (!isspace(str[i]))
        {
            if (word != -1)
                write(1," ", 1);
            word = i;
            while (!isspace(str[i]) && str[i])
                i++;
            write(1, &str[word], i - word);
            continue; 
        }
        i++;    
    }
    if (word != -1)
		write(1, " ", 1);
    write(1, &str[start], end - start);
}

int     main(int argc, char **argv)
{
    if (argc == 2)
    {
        rostring(argv[1]);
    }

    write(1,"\n",1);
    return(0);
}
