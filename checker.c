#include "push_swap.h"

static void	do_instructions(char **in, t_n *a)
{
	size_t	i;
	t_n		*b;

	i = -1;
	b = NULL;
	while (in[++i])
	{
		if (strequ(in[i], "pa"))
			push(a, b);
		else if (strequ(in[i], "pb"))
			push(b, a);
		else if (in[i][0] == 's')
			swap(a, b, in[i][1]);
		else 
			rotate(a, b, in[i]);
	}
}	

int			main(int ac, char **av)
{
	t_n		*a;
	char	**in;
	size_t	i;

	i = 0;
	if (!(a = load(ac, av)))
	{
		ft_putendl("Error");
		return (0);
	}
	i = list_size(a);
	in = solve(a, i);
	do_instructions(in, a);
	!sorted(a, i, 'a') ? ft_putendl("KO") : ft_putendl("OK");
	ft_strdel(in);
}
