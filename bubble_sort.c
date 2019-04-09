           #include "push_swap.h"

static int	list_min(t_n *s)
{
	int	min;

	min = s->v;
	while (s->next)
	{
		if (s->next->v < min)
			min = s->next->v;
		s = s->next;
	}
	return (min);
}

static int	list_max(t_n *s)
{
	int	max;

	max = s->v;
	while (s->next)
	{
		if (s->next->v > max)
			max = s->next->v;
		s = s->next;
	}
	return (max);
}

static void	sort_a(t_n *a, t_n *b, size_t i)
{
	int	max;
	int	min;

	max = list_max(a);
	min = list_min(b);
	while (!sorted(a, i - i / 2, 'a'))
	{
		if (a->v > a->next->v)
		{
			if (b->next && b->v < b->next->v)
				swap(a, b, 'r', 1);
			else
				swap(a, b, 'a', 1);
		}
		if (sorted(a, i - i / 2, 'a'))
			break ;
		sorted(b, i / 2, 'b') ? rotate(a, b, "ra", 1) : rotate(a, b, "rr", 1);
		if (a->v == max)
			(b->v == min) ? rotate(a, b, "rr", 1) : rotate(a, b, "ra", 1);
	}
}

static void	sort_b(t_n *a, t_n *b, size_t i)
{
	int	min;

	min = list_min(b);
	while (!sorted(b, i, 'b'))
	{
		if (b->v < b->next->v)
			swap(a, b, 'b', 1);
		if (sorted(b, i, 'b'))
			break ;
		rotate(a, b, "rb", 1);
		if (b->v == min)
			rotate(a, b, "rb", 1);
	}
}

void		bubble_sort(t_n *a, t_n *b, int c)
{
	if (c)
		sort_a(a, b, list_size(a) + list_size(b));
	else
		sort_b(a, b, list_size(b));
}
