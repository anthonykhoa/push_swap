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
		j = i;
		while (++j < k)
			if (tab[j] < tab[i])
			{
				tmp = tab[j];
				tab[j] = tab[i];
				tab[i] = tmp;
			}
	}
	i = -1;
	while (++i < k / 2)
		cut[i] = tab[i];
	free(*t);
	*t = cut;
}

static void	grow_big_b(t_n *a, t_n **b)
{
	if (list_size(a) == list_size(*b) || list_size(a) == list_size(*b) + 1)
		return ;
	push(b, &a, 0, 1);
	return (grow_big_b(a, b));
}

void		solve(t_n *a, int i)
{
	t_n		*b;
	int		*tab;

	b = NULL;
	g_in = ft_memalloc(sizeof(char*) * i * 400);
	if (sorted(a, i, 'a'))
		return ;
	if (i > 5) //later, make this 5 a 10
	{
		grow_big_b(a, &b);
		merge_sort(a, b, 1);
		return ;
	}
	tab = int_arr(a, i);
	cut_arr(&tab, i);
	grow_small_b(a, &b, &tab, i);
	if (!sorted(a, i - i / 2, 'a'))
		bubble_sort(a, b, 1);
	if (!sorted(b, i / 2, 'b'))
		bubble_sort(a, b, 0);
	i /= 2;
	while (i--)
		push(&a, &b, 1, 1);
	free(b);
}
