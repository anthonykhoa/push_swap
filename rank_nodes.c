#include "push_swap.h"

static void	rank_leftover_nodes(t_n *a, t_n **stack_b, int size, int n)
{
	t_n	*b;

	b = *stack_b;
	while (a && size--)
	{
		a->n = n;
		a = a->next;
	}
	while (b && size--)
	{
		b->n = n;
		b = b->next;
	}
}

static void	set_nodes(t_n *a, t_n **stack_b, int n)
{
	t_n	*b;

	b = *stack_b;
	while (a)
	{
		a->n = n;
		a = a->next;
	}
	while (b)
	{
		b->n = n;
		b = b->next;
	}
}

void		rank_nodes(t_n *a, t_n **stack_b, int size)
{
	t_n	*b;
	int	i;
	int	tmp;

	b = *stack_b;
	i = 1;
	tmp = size;
	size = 0;
	while (a && b)
	{
		size = tmp;
		while (size && a && b)
		{
			a->n = i;
			b->n = i;
			a = a->next;
			b = b->next;
			size--;
		}
		i++;
	}
	size ? rank_leftover_nodes(a, &b, size, --i) : set_nodes(a, &b, 0);
}
