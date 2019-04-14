/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 11:32:01 by anttran           #+#    #+#             */
/*   Updated: 2019/04/14 12:21:21 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_n *a, t_n *b, char *in)
{
	ft_printf("Instruction: %s\n", in);
	ft_printf("{RE}Stack A				{GR}Stack B\n");
	ft_printf("-------				-------\n");
	while (a && b)
	{
		ft_printf("%d				%d\n", a->v, b->v);
		a = a->next;
		b = b->next;
	}
	while (a)
	{
		ft_printf("%d\n", a->v);
		a = a->next;
	}
	while (b)
	{
		ft_printf("%d\n", b->v);
		b = b->next;
	}
	ft_printf("\n");
}
