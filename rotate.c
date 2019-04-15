/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 21:16:48 by anttran           #+#    #+#             */
/*   Updated: 2019/04/15 15:28:19 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ro(t_n *s)
{
	int	tmp;
	int tmp2;

	if (!s || !s->next)
		return ;
	tmp = s->v;
	tmp2 = s->n;
	while (s->next)
	{
		s->v = s->next->v;
		s->n = s->next->n;
		s = s->next;
	}
	s->v = tmp;
	s->n = tmp2;
}

static void	rr(t_n *s)
{
	int	tmp;
	int	tmp2;
	int	tmp3;
	int	tmp4;
	t_n	*t;

	if (!s || !s->next)
		return ;
	t = s;
	tmp = s->v;
	tmp3 = s->n;
	while (t->next)
		t = t->next;
	s->v = t->v;
	s->n = t->n;
	while (s->next)
	{
		tmp2 = s->next->v;
		tmp4 = s->next->n;
		s->next->v = tmp;
		s->next->n = tmp3;
		tmp = tmp2;
		tmp3 = tmp4;
		s = s->next;
	}
}

static void	add_instructions(char *in)
{
	if (in[1] == 'a')
		*(g_in + g_i++) = "ra";
	else if (in[1] == 'b')
		*(g_in + g_i++) = "rb";
	else if (!in[2])
	{
		*(g_in + g_i++) = "rr";
	}
	else if (in[2] == 'a')
		*(g_in + g_i++) = "rra";
	else if (in[2] == 'b')
		*(g_in + g_i++) = "rrb";
	else
	{
		*(g_in + g_i++) = "rrr";
	}
}

void		rotate(t_n *a, t_n *b, char *in, int x)
{
	if (in[1] == 'a')
		ro(a);
	else if (in[1] == 'b')
		ro(b);
	else if (!in[2])
	{
		ro(a);
		ro(b);
	}
	else if (in[2] == 'a')
		rr(a);
	else if (in[2] == 'b')
		rr(b);
	else
	{
		rr(a);
		rr(b);
	}
	if (x)
		add_instructions(in);
}
