#include "push_swap.h"

int	main(int ac, char **av)
{
	t_n		*a;
	char	**in;
	int		i;
	int		j;

	i = 0;
	a = malloc(sizeof(t_n));
	if (!(a = load(ac, av)))
	{
		ft_putendl("Error");
		return (0);
	}
	j = list_size(a);
	in = solve(a, j);
	while (in[i])
		ft_putendl(in[i++]);
	ft_printf("Sorted %d numbers in %d steps\n", j, i);
	//ft_strdel(in);
}
