#include "push_swap.h"

static int g_tmp;
static int g_tmp2;
static int g_tmp3;
static int g_tmp4;

static void	pop(t_n **stack)
{
	t_n	*d;
	t_n	*s;
	int	c;

	s = *stack;
	d = s;
	c = 0;
	if (s->next)
	{
		while (s->next)
		{
			if (c)
				d = d->next;
			c = 1;
			s->v = s->next->v;
			s->n = s->next->n;
			s = s->next;
		}
		free(d->next);
		d->next = NULL;
	}
	else
		*stack = NULL;
}

static void	handle_null_stack(t_n **stack, int v, int n)
{
	t_n	*s;

	*stack = malloc(sizeof(t_n));
	s = *stack;
	s->v = v;
	s->n = n;
	s->next = NULL;
}

static void	regular_push(t_n **stack, int v, int n)
{
	t_n	*s;

	s = *stack;
	g_tmp = s->v;
	g_tmp3 = s->n;
	s->v = v;
	s->n = n;
	while (s)
	{
		if (!(s->next))
		{
			s->next = malloc(sizeof(t_n));
			s->next->v = g_tmp;
			s->next->n = g_tmp3;
			s->next->next = NULL;
			break ;
		}
		g_tmp2 = s->next->v;
		g_tmp4 = s->next->n;
		s->next->v = g_tmp;
		s->next->n = g_tmp3;
		g_tmp3 = g_tmp4;
		g_tmp = g_tmp2;
		s = s->next;
	}
}

void		push(t_n **stack, t_n **p, int c, int x)
{
	if (!*stack)
		handle_null_stack(stack, (*p)->v, (*p)->n);
	else
		regular_push(stack, (*p)->v, (*p)->n);
	pop(p);
	if (x)
		*(g_in + g_i++) = c ? "pa" : "pb";
}
