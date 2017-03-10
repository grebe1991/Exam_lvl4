/*Assignment name  : fprime
Expected files   : fprime.c
Allowed functions: printf, atoi
--------------------------------------------------------------------------------

Write a program that takes a positive int and displays its prime factors on the
standard output, followed by a newline.

Factors must be displayed in ascending order and separated by '*', so that
the expression in the output gives the right result.

If the number of parameters is not 1, simply display a newline.

The input, when there's one, will be valid.

Examples:

$> ./fprime 225225 | cat -e
3*3*5*5*7*11*13$
$> ./fprime 8333325 | cat -e
3*3*5*5*7*11*13*37$
$> ./fprime 9539 | cat -e
9539$
$> ./fprime 804577 | cat -e
804577$
$> ./fprime 42 | cat -e
2*3*7$
$> ./fprime 1 | cat -e
1$
$> ./fprime | cat -e
$
$> ./fprime 42 21 | cat -e
$*/


#include <stdio.h>
#include <stdlib.h>

int     main(int argc,  char **argv)
{
    if (argc == 2)
    {
        long nb = atoi(argv[1]);
        int div = 0;
        if (nb == 0)
            printf("0");
        if (nb == 1)
            printf("1");
        while (nb > 1)
        {
            while (div < nb / 2)
            {
                if (nb % div == 0)
                {
                    printf("%d",div);
                    nb /= div;
                    break;
                }

            }
            if (nb > 1)
                printf("*");
        }

    }
    printf("\n");
    return(0);
}