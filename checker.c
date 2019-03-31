#include "push_swap.h"

static t_n	*stack_dup(t_n *s)
{
	t_n *dup;
	t_n *head;

	dup = malloc(sizeof(t_n));
	dup->v = s->v;
	head = dup;
	while (s->next)
	{
		dup->next = malloc(sizeof(t_n));
		dup->next->v = s->next->v;
		dup = dup->next;
		s = s->next;
	}
	dup->next = NULL;
	return (head);
}

static void	do_instructions(t_n *a)
{
	int	i;
	t_n	*b;

	i = -1;
	b = NULL;
	while (g_in[++i])
	{
		if (strequ(g_in[i], "pa"))
			push(&a, &b, 0, 0);
		else if (strequ(g_in[i], "pb"))
			push(&b, &a, 0, 0);
		else if (g_in[i][0] == 's')
			swap(a, b, g_in[i][1], 0);
		else
			rotate(a, b, g_in[i], 0);
	}
}

int			main(int ac, char **av)
{
	t_n	*a;
	t_n	*b;
	int	i;

	i = 0;
	if (!(a = load(ac, av)))
	{
		ft_putendl("Error");
		return (0);
	}
	b = stack_dup(a);
	i = list_size(a);
	solve(a, i);
	do_instructions(b);
	!sorted(b, i, 'a') ? ft_putendl("KO") : ft_putendl("OK");
}
