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

static t_n	*up(t_n *a, t_n *b, int v, char **in)
{
	t_n	*t;
	int	c;	

	t = a;
	c = 0;
	while (*in)
		in++;
	while (t)
	{
		if (t->v == v)
			break ;
		c++;
		t = t->next;
	}
	while (c--)
	{
		rotate(a, b, "ra");
		*in++ = ft_strdup("ra");
	}
	push(&b, a);
	*in = ft_strdup("pb");
	return (b);
}

static t_n	*down(t_n *a, t_n *b, int v, char **in)
{
	t_n	*t;
	int	c;
	int	size;	

	t = a;
	c = 0;
	size = list_size(a);
	while (*in)
		in++;
	while (t)
	{
		c++;
		if (t->v == v)
			break ;
		t = t->next;
	}
	c = size - c + 1;
	while (c--)
	{
		rotate(a, b, "rra");
		*in++ = ft_strdup("rra");
	}
	push(&b, a);
	*in = ft_strdup("pb");
	return (b);
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

char		**grow_b(t_n *a, t_n **b, int *tab, int i)
{
	char	**in;
	int		v;
	int		c;

	in = ft_memalloc(sizeof(char*) * i * 20);
	c = i / 2;
	while (list_size(*b) != c)
	{	
		if (direction(a, 1, tab, i))
		{
			v = fetch_value(a, tab, 1, c);
			*b = up(a, *b, v, in);
		}
		else
		{
			v = fetch_value(a, tab, 0, c);
			*b = down(a, *b, v, in);
		}
		tab = rem_int_arr_element(tab, i--, v); 
	}
	return (in);
}
