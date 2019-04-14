/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 21:04:04 by anttran           #+#    #+#             */
/*   Updated: 2019/04/13 21:04:06 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		list_size(t_n *s)
{
	int	i;

	i = 0;
	while (s)
	{
		i++;
		s = s->next;
	}
	return (i);
}

int		sorted(t_n *s, int i)
{
	if (list_size(s) != i)
		return (0);
	while (s)
	{
		if (s->next && s->v > s->next->v)
			return (0);
		s = s->next;
	}
	return (1);
}
