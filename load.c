#include "push_swap.h"
//make function to check if list a or b is sorted. if yes, mark global variable to indicate to stop checking that stack.

/*
if (option) execute instruction
else if (check tab and determine best instruction to use after)
1)make double array of input, then check each pointer in double array 
2)check if number is bigger than an int
3)at end of main solve function, have option for checker(global var) - if (global var) 
*/

int	duplicates_check(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (++i < ac)
	{
		j = 0;
		while (++j < ac)
			if ((i != j) && ft_strcmp(av[i], av[j]))
				return (0);
	}
	return (1);
}

int	overflow_check(int ac, char **av)
{
	ac--;
	av++;
	while (ac--)
	{
		if (ft_atoll(*av) < INT_MIN || ft_atoll(*av) > INT_MAX)
			return (0);
		av++;
	}
	return (1);
}

int	number_check(int ac, char **av)
{
	int	i;
	int	y;

	ac--;
	y = 1;
	while (ac--)
	{
		if (av[y][0] == '-' || av[y][0] == '+')
		{
			i = 0;
			while (av[y][++i])
				if (!ft_isdigit(av[y][i]))
					return (0);
		}
		else
		{
			i = -1;
			while (av[y][++i])
				if (!ft_isdigit(av[y][i]))
					return (0);
		}
		y++;
	}
	return (1);
}

t_n	*load(int ac, char **av)
{
	t_n	*a;
	t_n	*head;

	if (!number_check(ac, av) || !overflow_check(ac, av) ||
		!duplicates_check(ac, av))
		return (NULL);
	ac--;
	av++;
	a = malloc(sizeof(t_n));
	a->v = ft_atoi(*av++);
	head = a;
	while (--ac)
	{
		a->next = malloc(sizeof(t_n));
		a->next->v = ft_atoi(*av++);
		a = a->next;
	}
	a->next = NULL;
	return (head);
}
