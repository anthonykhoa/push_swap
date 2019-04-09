#include "push_swap.h"

static int check(t_n *s)
{
	int n;
	int t;
	int i;
	int l;

	n = 1;
	i = 0;
	t = 0;
	l = largest_node(s);
	while (n < l)
	{
		if (largest_node_element(s, n) < smallest_node_element(s, n + 1))
		{
			i++;
			while (s && s->n && s->n != n + 2)
			{
				s->n = -1;
				s = s->next;
			}
			n += 2;
		}
		else
		{
			++t;
			while (s && s->n == n)
			{
				s->n = t;
				s = s->next;
			}
			++n;
		}
	}
	if (n >= l)
	{
		++t;
		while (s && s->n == n)
		{
			s->n = t;
			s = s->next;
		}
	}
	return (i);
}

static void    cut_excess(t_n *s, int cs, int size, int biggest_node)
{
	int i;
	int tmp;
	int n;

	i = 0;
	tmp = size;
	n = 0;
	while (s)
	{
		if (s->n == -1)
		{
			i++;
			size = tmp;
			while (s && s->n == -1 && size--)
				s = s->next;
		}
		else
		{
			n = s->n;
			s = s->next;
		}
		if (i == cs)
			break ;
	}
	tmp /= 2;
	n++;
	while (s && (n != biggest_node + 1))
	{
		size = tmp;
		while (s && s->n && size--)
		{
			s->n = n;
			s = s->next;
		}
		n++;
	}
	//needa make option to make s->n = 0
}

void    sorted_nodes_check(t_n **a, t_n **b, int size)
{
	t_n	*a_dup;
	t_n	*b_dup;
	int ca;
	int cb;

	a_dup = stack_dup(*a);
	b_dup = stack_dup(*b);
	ca = check(*a);
	cb = check(*b);
	if (ca && cb && (ca == cb))
	{
		free(a_dup);
		free(b_dup);
	}
	else if (ca && cb)
		ca > cb ? cut_excess(*a, cb, size * 2, largest_node(*b)) :
		cut_excess(*b, ca, size * 2, largest_node(*a));
	else if (ca)
	{
		free(*a);
		free(b_dup);
		*a = a_dup;
	}
	else if (cb)
	{
		free(*b);
		free(a_dup);
		*b = b_dup;
	}
}
