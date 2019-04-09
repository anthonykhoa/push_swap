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

static void handle_leftovers(t_n *z, t_n *n, int size)
{
	size *= 2;
	if (n->n == -1)
	{
		while (n && size--)
		{
			n->n = -2;
			n = n->next;
		}
		while (z && z->n == 0)
		{
			z->n = -2;
			z = z->next;
		}
	}
	else
		while (z)
		{
			if (z->n == 0)
				z->n = n->n;
			z = z->next;
		}
}

int         sole_node(t_n *s, int n)
{
	while (s)
	{
		if (s->n != n)
			return (0);
		s = s->next;
	}
	return (1);
}

int         node_count(t_n *s, int n)
{
	int i;

	i = 0;
	while (s)
	{
		if (s->n == n)
			i++;
		s = s->next;
	}
	return (i);
}

static void	merge_nodes(t_n *s1, t_n *s2, int n)
{
	g_c = g_c ? 0 : 1;
	while (s1 && s1->n == -1 && (!sole_node(s1, -1)))
		r(s1);
	g_c = g_c ? 0 : 1;
	while (s2 && s2->n == -1 && (!sole_node(s2, -1)))
		r(s2);
	while (s1 && s1->n == n)
	{
		if (s1->v < s2->v)
		{
			push(&s2, &s1, g_c, 1);
			r(s2);
		}
		else
		{
			if ((s1->v > largest_node_element(s2, n)) && (last_value(s2) ==
						largest_node_element(s2, n)))
				push(&s2, &s1, g_c, 1);
			else
			{
				while (s1->v > s2->v && (s2->v != largest_node_element(s2, n)))
					r(s2);
				if (s1->v > s2->v)
					r(s2);
				push(&s2, &s1, g_c, 1);
			}
            //problem that i cycle thri -1 wen i dont want to
		}
		g_c = g_c ? 0 : 1;
		while (s1 && s1->n == -1 && (!sole_node(s1, -1)) && s2->n && !has_node(s1, n))
			r(s1);
		g_c = g_c ? 0 : 1;
		while (s2 && s2->n == -1 && (!sole_node(s2, -1)) && has_node(s1, n))
			r(s2);
	}
	while (last_value(s2) != largest_node_element(s2, n))
		r(s2);
}

static void	merge(t_n *a, t_n *b, int max_rank, int size)
{
	int	i;
	int n;

	i = 1;
	g_c = max_rank & 1 ? 1 : 0;
	while (max_rank--)
	{
		g_c ? merge_nodes(b, a, i++) : merge_nodes(a, b, i++);
		g_c = g_c ? 0 : 1;
	}
	if (a->n && !sole_node(a->next, a->n) &&
		(node_count(a, a->n) > (size * 2) || node_count(a, a->n) < (size * 2)))
	{
		g_c = 1;
		n = a->n;
		while (a->n == n)
			r(a);
	}
	else if (b->n && !sole_node(b->next, b->n) &&
		(node_count(b, b->n) > (size * 2) || node_count(b, b->n) < (size * 2)))
	{
		g_c = 0;
		n = b->n;
		while (b->n == n)
			r(b);
	}
	else if (a->n == 0)
	{
		handle_leftovers(a, b, size);
		g_c = 0;
		merge_nodes(a, b, b->n);
	}
	else if (b->n == 0)
	{
		handle_leftovers(b, a, size);
		g_c = 1;
		merge_nodes(b, a, a->n);
	}
}

void		merge_sort(t_n *a, t_n *b, int size)
{
	int	max_rank;

	rank_nodes(a, b, size);
	if (largest_node(b) == 1 && sole_node(b->next, 1))
	{
		if (has_node(a, 0))
		{
			g_c = 0;
			merge_nodes(a, b, 1);
		}
		g_c = 1;
		handle_leftovers(a, b, size);
		handle_leftovers(b, a, size);
		merge_nodes(b, a, 1);
		return ;
	}
	sorted_nodes_check(&a, &b, size); 
	max_rank = largest_node(b);
	if (max_rank == -1 && !has_node(a, 0) && !has_node(b, 0))
	{
		size *= 2;
		return (merge_sort(a, b, size));
	}
	merge(a, b, max_rank, size);
	size *= 2;
	return (merge_sort(a, b, size));
}
