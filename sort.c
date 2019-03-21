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

static void	sort_a(t_n *a, t_n *b, size_t i, char **in)
{
	int	max;
	int	min;

	max = list_max(a);
	min = list_min(b);
	while (*in)
		in++;
	while (!sorted(a, i - i / 2, 'a'))
	{
		if (a->v > a->next->v)
		{
			*in++ = (b->next && b->v < b->next->v) ?
			ft_strdup("ss") : ft_strdup("sa");
			(b->next && b->v < b->next->v) ? swap(a, b, 'r'): swap(a, b, 'a');
		}
		if (sorted(a, i - i / 2, 'a'))
			break ;
		*in++ = sorted(b, i / 2, 'b') ? ft_strdup("ra") : ft_strdup("rr");
		sorted(b, i / 2, 'b') ? rotate(a, b, "ra") : rotate(a, b, "rr");
		if (a->v == max)
		{
			*in++ =  (b->v == min) ? ft_strdup("rr") : ft_strdup("ra");
			(b->v == min) ? rotate(a, b, "rr") : rotate(a, b, "ra");
		}
	}
}

static void	sort_b(t_n *a, t_n *b, size_t i, char **in)
{
	int	min;

	min = list_min(b);
	while (*in)
		in++;
	while (!sorted(b, i, 'b'))
	{
		if (b->v < b->next->v)
		{
			*in++ = ft_strdup("sb");
			swap(a, b, 'b');
		}
		if (sorted(b, i, 'b'))
			break ;
		*in++ = ft_strdup("rb");
		rotate(a, b, "rb");
		if (b->v == min)
		{
			*in++ = ft_strdup("rb");
			rotate(a, b, "rb");
		}
		*in = NULL;
	}
}

void		sort(t_n *a, t_n *b, int c, char **in)
{
	//if 1 / 2 and i - 1 / 2 are the same u dunno which is which..
	if (c)
		sort_a(a, b, list_size(a) + list_size(b), in);
	else
		sort_b(a, b, list_size(b), in);
}
