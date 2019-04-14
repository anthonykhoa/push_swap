/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 21:17:43 by anttran           #+#    #+#             */
/*   Updated: 2019/04/13 21:17:43 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3(t_n *a)
{
	a->n = 1;
	a->next->n = 1;
	a->next->next->n = 1;
	if (a->v == largest_node_element(a, 1))
	{
		rotate(a, NULL, "ra", 1);
		if (a->v > a->next->v)
			swap(a, NULL, 'a', 1);
	}
	else if (a->next->v == largest_node_element(a, 1))
	{
		if (a->v < a->next->next->v)
			swap(a, NULL, 'a', 1);
		rotate(a, NULL, "ra", 1);
	}
	else if (a->v > a->next->v)
		swap(a, NULL, 'a', 1);
}

static void	sort_4(t_n *a, t_n *b)
{
	if (a->v > a->next->v)
		b->v > b->next->v ? swap(a, b, 's', 1) : swap(a, b, 'a', 1);
	if (b->v > b->next->v)
		swap(a, b, 'b', 1);
	merge_sort(a, b, 2);
}

static void	sort_5(t_n *a, t_n *b)
{
	sort_3(a);
	sort_4(a, b);
}

static void	grow_b(t_n *a, t_n **b)
{
	if (list_size(a) == list_size(*b) || list_size(a) == list_size(*b) + 1)
		return ;
	push(b, &a, 0, 1);
	return (grow_b(a, b));
}

void		solve(t_n *a, int i)
{
	t_n		*b;

	b = NULL;
	g_in = ft_memalloc(sizeof(char*) * i * 400);
	if (sorted(a, list_size(a)))
		return ;
	if (i > 3)
		grow_b(a, &b);
	if (i > 5)
	{
		if (list_size(a) == list_size(b))
		{
			pre_msort(a, b);
			merge_sort(a, b, 2);
		}
		else
			merge_sort(a, b, 1);
	}
	else if (i == 3)
		sort_3(a);
	else if (i == 4)
		sort_4(a, b);
	else if (i == 5)
		sort_5(a, b);
}
