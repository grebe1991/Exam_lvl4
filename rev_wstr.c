/*Assignment name  : rev_wstr
Expected files   : rev_wstr.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string as a parameter, and prints its words in 
reverse order.

A "word" is a part of the string bounded by spaces and/or tabs, or the 
begin/end of the string.

If the number of parameters is different from 1, the program will display 
'\n'.

In the parameters that are going to be tested, there won't be any "additional" 
spaces (meaning that there won't be additionnal spaces at the beginning or at 
the end of the string, and words will always be separated by exactly one space).

Examples:

$> ./rev_wstr "le temps du mepris precede celui de l'indifference" | cat -e
l'indifference de celui precede mepris du temps le$
$> ./rev_wstr "abcdefghijklm"
abcdefghijklm
$> ./rev_wstr "il contempla le mont" | cat -e
mont le contempla il$
$> ./rev_wstr | cat -e
$
$>*/

#include <stdlib.h>
#include <unistd.h>
#define isspace(c) ( (c) == ' ' )
int     get_len(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return(i);    
}


char    *rev_str(char *str)
{
    int i = 0;
    int len = get_len(str);
    char *rev;

    rev = (char*)malloc(sizeof(char) * (len + 1));
    rev[len] = '\0';
    len--;
    while (str[i])
    {
        rev[len] = str[i];
        len--;
        i++;
    }
    return(rev);
}

void    rev_words(char *str)
{
    int i = 0;
    int start = 0;
    int end = 0;
    //erem era anA
    //mere are Ana
    while (str[i])
    {    
        if(!isspace(str[i]))
            start = i;
        while (!isspace(str[i]) && str[i])
            i++;
        end = i - 1;    
        while (end >= start)
        {
           write(1, &str[end], 1);
           end--;     
        }
        if (str[i + 1])
        {
            write(1, " ", 1);    
        }         
        i++;    
    }
}




int     main(int argc, char**argv)
{
    if (argc == 2)
    {
        char *rev;
        rev = rev_str(argv[1]);
        rev_words(rev);
    }
    write(1, "\n", 1);
    return(0);
}