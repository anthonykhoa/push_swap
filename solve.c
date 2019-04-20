/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 21:17:43 by anttran           #+#    #+#             */
/*   Updated: 2019/04/14 19:06:39 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3(t_n *a, t_n *b, int i)
{
	a->n = 1;
	a->next->n = 1;
	a->next->next->n = 1;
	if (a->v == largest_node_element(a, 1))
	{
		rotate(a, NULL, "ra", 1);
		if (a->v > a->next->v)
			(i > 3) && (b->v > b->next->v) ?
			swap(a, b, 's', 1) : swap(a, NULL, 'a', 1);
	}
	else if (a->next->v == largest_node_element(a, 1))
	{
		if (a->v < a->next->next->v)
			(i > 3) && (b->v > b->next->v) ?
			swap(a, b, 's', 1) : swap(a, NULL, 'a', 1);
		rotate(a, NULL, "ra", 1);
	}
	else if (a->v > a->next->v)
		(i > 3) && (b->v > b->next->v) ?
		swap(a, b, 's', 1) : swap(a, NULL, 'a', 1);

}

static void	small_sort(t_n *a, t_n *b, int i)
{
	if (i == 2 && (a->v > a->next->v))
		swap(a, b, 'a', 1);
	else if (i == 3)
		sort_3(a, b, i);
	else if (i == 4)
	{	
		if (a->v > a->next->v)
			b && b->v > b->next->v ? swap(a, b, 's', 1) : swap(a, b, 'a', 1);
		if (b && b->v > b->next->v)
			swap(a, b, 'b', 1);
		merge_sort(a, b, 2);
	}
	else if (i == 5)
	{
		sort_3(a, b, i);
		merge_sort(a, b, 2);
	}
}

void		solve(t_n *a, int i)
{
	t_n		*b;

	b = NULL;
	g_in = ft_memalloc(sizeof(char*) * i * 400);
	if (((list_size(a) == 1)) || sorted(a, list_size(a)))
		return ;
	if (i > 3)
		while (list_size(a) != list_size(b) && list_size(a) != list_size(b) + 1)
			push(&b, &a, 0, 1);
	if (i < 6)
		small_sort(a, b, i);
	else
	{
		if (list_size(a) > 10 && (list_size(a) == list_size(b)))
		{
			pre_msort(a, b);
			merge_sort(a, b, 2);
		}
		else
			merge_sort(a, b, 1);
	}
}
