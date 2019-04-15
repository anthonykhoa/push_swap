/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_number_generator.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 13:14:33 by anttran           #+#    #+#             */
/*   Updated: 2019/04/15 16:14:18 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <fcntl.h>
#include "push_swap.h"

static int	new_num(int r, int *tab, int i)
{
	int	x;

	x = -1;
	while (++x < i)
		if (tab[x] == r)
			return (0);
	return (1);
}

static void	print_nums(int n, int fd)
{
	int			i;
	intmax_t	r;
	int			*tab;

	i = 0;
	tab = malloc(sizeof(int) * n);
	srand(time(0));
	while (i != n)
	{
		r = rand() / 100000;
		if (new_num(r, tab, i))
			tab[i++] = r;
	}
	i = 0;
	while (i < n)
		ft_fprintf(fd, "%d ", tab[i++]);
	ft_fprintf(fd, "\n");
	free(tab);
}

int			main(int ac, char **av)
{
	int	fd;

	fd = open("nums", O_WRONLY);
	if (ac == 2)
		print_nums(ft_atoi(av[1]), fd);
	close(fd);
}
