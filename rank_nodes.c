/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 21:16:28 by anttran           #+#    #+#             */
/*   Updated: 2019/04/13 21:16:29 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int g_va;
static int g_vb;

static void	set_b(t_n *b, int n)
{
	if (b->v > g_vb)
	{
		while (b)
		{
			b->n = n;
			b = b->next;
		}
	}
	else
		while (b)
		{
			b->n = 0;
			b = b->next;
		}
}

static void	set_nodes(t_n *a, t_n *b, int n)
{
	if (a)
	{
		if (a->v > g_va)
		{
			while (a)
			{
				a->n = n;
				a = a->next;
			}
		}
		else
			while (a)
			{
				a->n = 0;
				a = a->next;
			}
	}
	else if (b)
		set_b(b, n);
}

static void	rank_leftover_nodes(t_n *a, t_n *b, int size, int n)
{
	if (a)
		while (a && size--)
		{
			a->n = n;
			g_va = a->v;
			a = a->next;
		}
	if (b)
		while (b && size--)
		{
			b->n = n;
			g_vb = b->v;
			b = b->next;
		}
	set_nodes(a, b, n);
}

void		rank_nodes(t_n *a, t_n *b, int size)
{
	int	i;
	int	tmp;

	i = 1;
	tmp = size;
	while (a && b)
	{
		size = tmp;
		while (a && b && size)
		{
			a->n = i;
			g_va = a->v;
			g_vb = b->v;
			b->n = i;
			a = a->next;
			b = b->next;
			size--;
		}
		i++;
	}
	--i;
	if (size)
		rank_leftover_nodes(a, b, size, i);
	else
		set_nodes(a, b, i);
}
