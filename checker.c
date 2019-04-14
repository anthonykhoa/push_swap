/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 21:07:30 by anttran           #+#    #+#             */
/*   Updated: 2019/04/14 09:23:54 by anttran          ###   ########.fr       */
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

static void	sad_exit(void)
{
	ft_putendl("Error :(");
	exit(1);
}

static int	instruction_check(char *in)
{
	if (!strequ(in, "sa") && !strequ(in, "sb") && !strequ(in, "ss")
		&& !strequ(in, "ra") && !strequ(in, "rb") && !strequ(in, "rr")
		&& !strequ(in, "rra") && !strequ(in, "rrb") && !strequ(in, "rrr")
		&& !strequ(in, "pa") && !strequ(in, "pb"))
		return (0);
	return (1);
}

static void	stdin_instructions(t_n *a)
{
	char	*str;
	t_n		*b;

	b = NULL;
	while (get_next_line(0, &str))
	{
		if (strequ(str, ""))
		{
			free(str);
			break ;
		}
		if (!instruction_check(str))
			sad_exit();
		if (strequ(str, "pa"))
			push(&a, &b, 0, 0);
		else if (strequ(str, "pb"))
			push(&b, &a, 0, 0);
		else if (str[0] == 's')
			swap(a, b, str[1], 0);
		else
			rotate(a, b, str, 0);
		free(str);
	}
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
	{
		solve(a, i);
		in = cut_down();
		do_instructions(b, in);
	}
	else
		stdin_instructions(a);
	!sorted(b, i) ? ft_putendl("KO") : ft_putendl("OK");
}
