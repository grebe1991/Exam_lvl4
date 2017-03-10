/*Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:*/

#include <stdio.h>
#include <stdlib.h>

int     count_digits(int nbr)
{
    int digits = 1;
    if (nbr < 0)
        nbr *= -1;
    if (nbr < 10 )
        return(digits);
    while (nbr >= 10)
    {
        nbr = nbr / 10;
        digits ++;
    }
    return(digits);
}
char	*ft_itoa(int nbr)
{
    char *nb;
    int  neg = 0;
    int  len = count_digits(nbr);
    if (nbr < 0)
    {
        neg = 1;
        nbr = nbr * -1;
        
    }
    nb = (char*)malloc(sizeof(char) * (len + neg));
    nb[len + neg] = '\0';
    while (nbr > 0)
    {
        nb[len + neg - 1] = nbr % 10 + '0';
        nbr /= 10;
        len--;
    }
    if (neg == 1)
        nb[0] = '-';
    return(nb);    
}

int     main(int argc,  char **argv)
{
    if (argc > 1)
    {
        int n = atoi(argv[1]);

        char* digits = ft_itoa(n);
        printf("%s",digits);
        printf("\n");
    }

    return(0);
}