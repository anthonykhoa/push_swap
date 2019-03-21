#include "push_swap.h"

int	*rem_int_arr_element(int *arr, int c, int v)
{
	int	*tab;
	int	i;
	int	j;

	tab = malloc(sizeof(int) * (c - 1));
	i = -1;
	j = 0;
	while (++i < c)
		if (arr[i] != v)
			tab[j++] = arr[i];
	return (tab);
}
