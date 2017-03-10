/*
Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str);
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define isspace(c) ( (c) == '\t' || (c) == ' ' || (c) == '\n')

int     count_chars(char *str)
{

    int i = 0;

    while (str[i])     
        i++;
    return(i);
}
int		ft_isnot(int c)
{
	if (c != 10 && c != 32 && c != 9)
		return (1);
	return (0);
}
char    *make_word(char const *str, int start, int len)
{
    char *word;
    int i;

    i = 0;
    if (!str || !(word = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
    while (i < len)
    {
       word[i] = str[start + i];
       i++;
    }
    word[i] = '\0';
    return(word);
}
char    **ft_split(char *str)
{
    char** split;
    int size = 0;
    int i = 0;
    int start = 0;
    
    if (!str || !(split = (char**)malloc(sizeof(char *) * (count_chars(str) + 1))))
		return (NULL);   
    while (str[i])
    {
        if (!isspace(str[i]))
        {
            start = i;
            while(!isspace(str[i]) && str[i])
                i++;
            split[size] = make_word(str, start, i - start);
            size++;

        }
        else
            i++;                  
    }
    split[size] = NULL;
    return(split);
}

int     main(int argc, char**argv)
{
    if (argc > 1)
    {
        char **split;

        split = ft_split(argv[1]);
        printf("%s", split[0]);
        printf("\n");
        printf("%s", split[1]);
        printf("\n");
        printf("%s", split[2]);
        printf("\n");
        

    }
    printf("\n");
    return(0);
}