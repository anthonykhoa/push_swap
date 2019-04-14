/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_funcs2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 21:18:40 by anttran           #+#    #+#             */
/*   Updated: 2019/04/13 21:18:41 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sole_node(t_n *s, int n)
{
	while (s)
	{
		if (s->n != n)
			return (0);
		s = s->next;
	}
	return (1);
}

int		node_count(t_n *s, int n)
{
	int i;

	i = 0;
	while (s)
	{
		if (s->n == n)
			i++;
		s = s->next;
	}
	return (i);
}

void	handle_leftovers(t_n *z, t_n *n, int size)
{
	size *= 2;
	if (n->n == -1)
	{
		while (n && size--)
		{
			n->n = -2;
			n = n->next;
		}
		while (z && z->n == 0)
		{
			z->n = -2;
			z = z->next;
		}
	}
	else
		while (z)
		{
			if (z->n == 0)
				z->n = n->n;
			z = z->next;
		}
}

int		last_node(t_n *s)
{
	while (s->next)
		s = s->next;
	return (s->n);
}
