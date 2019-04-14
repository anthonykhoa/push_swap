/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_msort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 21:19:27 by anttran           #+#    #+#             */
/*   Updated: 2019/04/13 21:19:28 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	last_to_zero(t_n *s)
{
	while (s->next)
		s = s->next;
	s->n = 0;
}

static void	finish_presort(t_n *a, t_n *b)
{
	int i;

	i = 0;
	if (!a->n && !b->n)
	{
		if (a->v < b->n)
		{
			rotate(a, b, "ra", 1);
			push(&a, &b, 1, 1);
		}
		else
		{
			push(&a, &b, 1, 1);
			rotate(a, b, "ra", 1);
		}
		rotate(a, b, "ra", 1);
	}
}

void		pre_msort(t_n *a, t_n *b)
{
	int x;
	int x2;
	int c;

	x = a->v;
	x2 = a->next->v;
	c = 1;
	rank_nodes(a, b, 1);
	if (list_size(a) & 1)
	{
		last_to_zero(a);
		last_to_zero(b);
	}
	while (((a->v != x && a->v != x2) || c) && a->n)
	{
		if (a->v > a->next->v)
			b->v > b->next->v ? swap(a, b, 's', 1) : swap(a, b, 'a', 1);
		if (b->v > b->next->v)
			swap(a, b, 'b', 1);
		rotate(a, b, "rr", 1);
		rotate(a, b, "rr", 1);
		c = 0;
	}
	finish_presort(a, b);
}
