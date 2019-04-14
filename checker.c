/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 21:07:30 by anttran           #+#    #+#             */
/*   Updated: 2019/04/13 21:07:33 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void	stdin_instructions(char **in)
{
	while (get_next_line(0, in))
	{
		if (!**in)
			break ;
		in++;
	}
	*in = NULL;
}

static int	instructions_check(char **in)
{
	while (*in)
	{
		if (!strequ(*in, "pa") && !strequ(*in, "pb") && !strequ(*in, "sa")
			&& !strequ(*in, "sb") && !strequ(*in, "ss") && !strequ(*in, "ra")
			&& !strequ(*in, "rb") && !strequ(*in, "rr") && !strequ(*in, "rra")
			&& !strequ(*in, "rrb") && !strequ(*in, "rrr"))
			return (0);
		in++;
	}
	return (1);
}

int			main(int ac, char **av)
{
	t_n		*a;
	t_n		*b;
	int		i;
	char	**in;

	if (!(a = load(ac, av)) || ac == 1)
	{
		!a ? ft_putendl("Error") : 0;
		return (0);
	}
	b = load(ac, av);
	i = list_size(a);
	if (g_plz)
		solve(a, i);
	in = g_plz ? cut_down() : ft_memalloc(sizeof(char*) * i * 400);
	if (!g_plz)
		stdin_instructions(in);
	if (!instructions_check(in))
	{
		ft_putendl("Error");
		return (0);
	}
	do_instructions(b, in);
	!sorted(b, i) ? ft_putendl("KO") : ft_putendl("OK");
	system("leaks checker");
}
