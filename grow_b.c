#include "push_swap.h"

static int	direction(t_n *s, int c, int *tab, size_t i)
{
	int	top;
	int	bot;
	int	save;
	int	tmp;

	bot = 0;
	save = 0;
	tmp = i;
	while (s)
	{	
		save++;
		i = tmp;
		while (i--)
			if (s->v == tab[i])
			{
				if (c)
					top = save - 1;
				else
					bot = save;
				c = 0;
			}
		s = s->next;
	}
	!bot ? bot = top : 0;
	return (top <= tmp - bot ? 1 : 0);
}

static void	up(t_n *a, t_n *b, int v, char **in)
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
	push(b, a);
	*in++ = ft_strdup("pb");
	*in = NULL;
}

static void	down(t_n *a, t_n *b, int v, char **in)
{
	t_n	*t;
	int	c;	

	t = a;
	c = 0;
	while (*in)
		in++;
	while (t)
	{
		c++;
		if (t->v == v)
			break ;
		t = t->next;
	}
	while (c--)
	{
		rotate(a, b, "rra");
		*in++ = ft_strdup("rra");
	}
	push(b, a);
	*in++ = ft_strdup("pb");
	*in = NULL;
}

static int	fetch_value(t_n *s, int *tab, int c, size_t i)
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

char		**grow_b(t_n *a, t_n *b, int *tab, size_t i)
{
	char	**in;
	int		v;

	in = ft_memalloc(sizeof(char*) * i * 20);
	i /= 2;
	while (list_size(b) != i)
	{
		if (direction(a, 1, tab, i))
		{
			v = fetch_value(a, tab, 1, i);
			up(a, b, v, in);
		}
		else
		{
			v = fetch_value(a, tab, 0, i);
			down(a, b, v, in);
		}
	}
	return (in);
}
