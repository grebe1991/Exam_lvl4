/*Assignment name  : sort_int_tab
Expected files   : sort_int_tab.c
Allowed functions: 
--------------------------------------------------------------------------------

Write the following function:

void sort_int_tab(int *tab, unsigned int size);

It must sort (in-place) the 'tab' int array, that contains exactly 'size'
members, in ascending order.

Doubles must be preserved.

Input is always coherent.*/

void sort_int_tab(int *tab, unsigned int size)
{
    unsigned int i = 1;
    int swap = 0;
    if (size != 0)
    {

        while (i < size)
        {
            if (tab[i] < tab[i - 1])
            {
                swap = tab[i];
                tab[i] = tab[i - 1];
                tab[i - 1] = swap;
                i = 0;
            }
            i++;
        }
    }
}