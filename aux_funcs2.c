#include "push_swap.h"

int	has_node(t_n *s, int n)
{
	while (s)
	{
		if (s->n == n)
			return (1);
		s = s->next;
	}
	return (0);
}

int	last_value(t_n *s)
{
	while (s->next)
		s = s->next;
	return (s->v);
}

int	last_node_value(t_n *s)
{
	while (s->next)
		s = s->next;
	return (s->n);
}

int	largest_node_element(t_n *s, int n)
{
	int	i;
	int	*tab;

	i = 0;
	tab = malloc(sizeof(int) * list_size(s));
	while (s)
	{
		if (s->n == n)
			tab[i++] = s->v;
		s = s->next;
	}
	i = max(tab, i);
	free(tab);
	return (i);
}

int	largest_node(t_n *s)
{
	int	i;

	i = s->n;
	while (s)
	{
		if (s->n > i)
			i = s->n;
		s = s->next;
	}
	return (i);
}
