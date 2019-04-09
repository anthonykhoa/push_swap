#include "push_swap.h"

static void	do_instructions(t_n *a, char **in)
{
	int	i;
	t_n	*b;

	i = -1;
	b = NULL;
	while (in[++i])
	{
		if (strequ(in[i], "pa"))
			push(&a, &b, 0, 0);
		else if (strequ(in[i], "pb"))
			push(&b, &a, 0, 0);
		else if (in[i][0] == 's')
			swap(a, b, in[i][1], 0);
		else
			rotate(a, b, in[i], 0);
	}
}

int			main(int ac, char **av)
{
	t_n	*a;
	t_n	*b;
	int	i;
    char        **in;

	i = 0;
	if (!(a = load(ac, av)))
	{
		ft_putendl("Error");
		return (0);
	}
	b = stack_dup(a);
	i = list_size(a);
	solve(a, i);
    in = cut_down();
	do_instructions(b, in);
	!sorted(b, i, 'a') ? ft_putendl("KO") : ft_putendl("OK");
}
