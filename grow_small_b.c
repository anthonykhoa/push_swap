#include "push_swap.h"

static int	g_top;

static int	direction(t_n *s, int c, int *tab, int i)
{
	int	bot;
	int	save;
	int	tmp;

	bot = 0;
	save = 0;
	tmp = i;
	while (s)
	{
		save++;
		i = tmp / 2;
		while (i--)
			if (s->v == tab[i])
			{
				if (c)
					g_top = save - 1;
				bot = save;
				c = 0;
			}
		s = s->next;
	}
	!bot ? bot = g_top : 0;
	return (g_top <= tmp - bot + 1 ? 1 : 0);
}

static void	up(t_n *a, t_n **b, int v)
{
	t_n	*t;
	int	c;

	t = a;
	c = 0;
	while (t)
	{
		if (t->v == v)
			break ;
		c++;
		t = t->next;
	}
	while (c--)
	{
		rotate(a, *b, "ra", 1);
	}
	push(b, &a, 0, 1);
}

static void	down(t_n *a, t_n **b, int v)
{
	t_n	*t;
	int	c;
	int	size;

	t = a;
	c = 0;
	size = list_size(a);
	while (t)
	{
		c++;
		if (t->v == v)
			break ;
		t = t->next;
	}
	c = size - c + 1;
	while (c--)
		rotate(a, *b, "rra", 1);
	push(b, &a, 0, 1);
}

static int	fetch_value(t_n *s, int *tab, int c, int i)
{
	int	tmp;
	int	bot;

	tmp = i;
	while (s)
	{
		i = tmp;
		while (i--)
			if (s->v == tab[i])
			{
				if (c)
					return (s->v);
				else
					bot = tab[i];
			}
		s = s->next;
	}
	return (bot);
}

void		grow_small_b(t_n *a, t_n **b, int **tab, int i)
{
	int		v;
	int		c;
	int		t;

	c = i / 2;
	t = i / 2;
	while (list_size(*b) != c)
	{
		if (direction(a, 1, *tab, t))
		{
			v = fetch_value(a, *tab, 1, t);
			up(a, b, v);
		}
		else
		{
			v = fetch_value(a, *tab, 0, t);
			down(a, b, v);
		}
		rem_int_arr_element(tab, t--, v);
	}
	free(*tab);
}
