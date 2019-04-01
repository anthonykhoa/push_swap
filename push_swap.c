#include "push_swap.h"

int	main(int ac, char **av)
{
	t_n		*a;
	int		i;
	int		j;
	char		**in;

	i = 0;
	if (!(a = load(ac, av)))
	{
		ft_putendl("Error");
		return (0);
	}
	j = list_size(a);
	solve(a, j);
	in = cut_down();
	while (in[i])
		i++;
	ft_printf("Sorted %d numbers in %d steps\n", j, i);
}
