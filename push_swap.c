/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 21:11:22 by anttran           #+#    #+#             */
/*   Updated: 2019/04/14 09:34:13 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_n		*a;
	int		i;
	int		j;
	char	**in;

	i = 0;
	if (ac == 1)
		return (0);
	if (!(a = load(ac, av)))
	{
		ft_putendl("Error");
		return (0);
	}
	j = list_size(a);
	solve(a, j);
	in = cut_down();
	while (in[i])
		ft_putendl(in[i++]);
	ft_printf("Sorted %d numbers in %d steps\n", j, i);
}
