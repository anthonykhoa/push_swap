#include "push_swap.h"

int		list_size(t_n *s)
{
	int	i;

	i = 0;
	while (s)
	{
		i++;
		s = s->next;
	}
	return (i);
}

int		sorted(t_n *s, int i, char c)
{
	if (list_size(s) != i)
		return (0);
	if (c == 'a')
		while (s)
		{
			if (s->next && s->v > s->next->v)
				return (0);
			s = s->next;
		}
	else
		while (s)
		{
			if (s->next && s->v < s->next->v)
				return (0);
			s = s->next;
		}
	return (1);
}

void	rem_int_arr_element(int **arr, int c, int v)
{
	int	*tab;
	int	i;
	int	j;

	tab = malloc(sizeof(int) * (c - 1));
	i = -1;
	j = 0;
	while (++i < c)
		if (arr[0][i] != v)
			tab[j++] = arr[0][i];
	free(*arr);
	*arr = tab;
}

int		no_different_nodes(t_n *s)
{
	int	c;

	c = s->n;
	while (s)
	{
		if (s->n != c)
			return (0);
		s = s->next;
	}
	return (1);
}

void	handle_leftovers(t_n **stack, int n)
{
	t_n	*s;

	s = *stack;
	while (s)
	{
		if (s->n == 0)
			s->n = n;
		s = s->next;
	}
}