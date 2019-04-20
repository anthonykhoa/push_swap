/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 21:09:26 by anttran           #+#    #+#             */
/*   Updated: 2019/04/14 12:10:15 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int g_check_ops;

static int	duplicates_check(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (++i < ac)
	{
		j = i;
		while (++j < ac)
			if (!ft_strcmp(av[i], av[j]))
				return (0);
	}
	return (1);
}

static int	overflow_check(int ac, char **av)
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

static int	number_check(int ac, char **av)
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

int			check_options(int ac, char **av)
{
	int	i;

	i = 0;
	if (strequ(av[1], "plz") || strequ(av[1], "-v"))
		i++;
	if (ac > 2 && (strequ(av[2], "plz") || strequ(av[2], "-v")))
		i++;
	if (strequ(av[1], "plz") || (ac > 2 && strequ(av[2], "plz")))
		g_plz++;
	if (strequ(av[1], "-v") || (ac > 2 && strequ(av[2], "-v")))
		g_v++;
	return (i);
}

t_n			*load(int ac, char **av)
{
	t_n	*a;
	t_n	*head;

	g_check_ops = check_options(ac, av);
	while (g_check_ops--)
	{
		ac--;
		av++;
	}
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
