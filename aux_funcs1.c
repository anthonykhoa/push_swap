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

t_n	*stack_dup(t_n *s)
{
	t_n *dup;
	t_n *head;

	dup = malloc(sizeof(t_n));
	dup->v = s->v;
	dup->n = s->n;
	head = dup;
	while (s->next)
	{
		dup->next = malloc(sizeof(t_n));
		dup->next->v = s->next->v;
		dup->next->n = s->next->n;
		dup = dup->next;
		s = s->next;
	}
	dup->next = NULL;
	return (head);
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
