#include "push_swap.h"

static int g_c;

static void	r(t_n *s)
{
	int	tmp;
	int	tmp2;

	tmp = s->v;
	tmp2 = s->n;
	while (s->next)
	{
		s->v = s->next->v;
		s->n = s->next->n;
		s = s->next;
	}
	s->v = tmp;
	s->n = tmp2;
	*(g_in + g_i++) = g_c ? "ra" : "rb";
}

static void	y_u_so_big(t_n **stack_1, t_n **stack_2, int n, int c)
{
	t_n	*s2;

	s2 = *stack_2;
	if (c)
		while ((*stack_1)->v > s2->v && s2->n == n &&
				(last_value(s2) != largest_node_element(s2, n)))
			r(s2);
	else
		while ((*stack_1)->v > s2->v && (s2->v != largest_node_element(s2, n)))
			r(s2);
	if (s2->v == largest_node_element(s2, n) && !c && (*stack_1)->v > s2->v)
		r(s2);
	push(&s2, stack_1, g_c, 1);
}

static void	merge_nodes(t_n **stack_1, t_n **stack_2, int n)
{
	t_n	*s2;
	int	c;

	s2 = *stack_2;
	c = no_different_nodes(s2) ? 0 : 1;
	while (*stack_1 && (*stack_1)->n == n)
	{
		if ((*stack_1)->v < s2->v)
		{
			push(&s2, stack_1, g_c, 1);
			r(s2);
		}
		else
			y_u_so_big(stack_1, &s2, n, c);
	}
	if (!no_different_nodes(s2))
		while (s2->n == n)
			r(s2);
	else if (*stack_1 && no_different_nodes(s2) && c)
		while (!sorted(s2, list_size(s2), 'a'))
			r(s2);
	else if (last_value(s2) != largest_node_element(s2, n))
		while (last_value(s2) != largest_node_element(s2, n))
			r(s2);
}

static void	merge(t_n *a, t_n **b, int max_rank)
{
	int	i;

	i = 1;
	g_c = max_rank & 1 ? 1 : 0;
	while (max_rank--)
	{
		g_c ? merge_nodes(b, &a, i++) : merge_nodes(&a, b, i++);
		g_c = g_c ? 0 : 1;
	}
	if (a->n == 0)
	{
		handle_leftovers(&a, (*b)->n);
		g_c = 0;
		merge_nodes(&a, b, (*b)->n);
	}
	else if ((*b)->n == 0)
	{
		handle_leftovers(b, a->n);
		g_c = 1;
		merge_nodes(b, &a, a->n);
	}
}

void		merge_sort(t_n *a, t_n **b, int size)
{
	int	max_rank;

	rank_nodes(a, b, size);
	max_rank = largest_node(*b);
	if (max_rank == 1)
	{
		rank_nodes(a, b, size);
		if (has_node(a, 0))
		{
			g_c = 0;
			merge_nodes(&a, b, 1);
		}
		g_c = 1;
		handle_leftovers(&a, 1);
		handle_leftovers(b, 1);
		merge_nodes(b, &a, 1);
		return ;
	}
	merge(a, b, max_rank);
	size *= 2;
	return (merge_sort(a, b, size));
}
