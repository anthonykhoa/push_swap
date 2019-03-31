#include "push_swap.h"

int	main(int ac, char **av)
{
	t_n		*a;
	int		i;
	int		j;

	i = 0;
	if (!(a = load(ac, av)))
	{
		ft_putendl("Error");
		return (0);
	}
	j = list_size(a);
	solve(a, j);
	ft_printf("%d", j);
	while (g_in[i])
		ft_putendl(g_in[i++]);
	ft_printf("Sorted %d numbers in %d steps\n", j, i);
}
