#include "push_swap.h"

static int	*int_arr(t_n *a, int i)
{
	int	*tab;

	tab = malloc(sizeof(int) * i);
	while (a)
	{
		tab[--i] = a->v;
		a = a->next;
	}
	return (tab);
}

static void	cut_arr(int **t, int k)
{
	int	i;
	int	j;
	int	tmp;
	int	*tab;
	int	*cut;

	i = -1;
	tab = *t;
	cut = malloc(sizeof(int) * (k / 2));
	while (++i < k)
	{
		j = -1;
		while (++j < k)
			if (j > i && tab[j] < tab[i])
			{
				tmp = tab[j];
				tab[j] = tab[i];
				tab[i] = tmp;
			}
	}
	i = k / 2 - 1;
	while (++i < k - 1)
		cut[i - k / 2] = tab[i + 1];
	//free(*t);
	*t = cut;
}

static void	finish(char	**in, t_n *a, t_n *b, size_t i)
{
	while (*in)
		in++;
	while (i--)
	{
		*in++  = ft_strdup("pa");
		push(a, b);
	}
}

char		**solve(t_n *a, size_t i)
{
	char	**in;
	t_n		*b;
	int		*tab;

	b = NULL;
	tab = int_arr(a, i);
	cut_arr(&tab, i);
	in = grow_b(a, b, tab, i);
	if (!sorted(a, i - i / 2, 'a'))
		sort(a, b, i, in);
	if (!sorted(b, i / 2, 'b'))
		sort(a, b, i / 2, in);
	finish(in, a, b, i / 2);
	//free(b);
	return (in);
}
