#include "push_swap.h"

static void	r(t_n *s)
{
	int	tmp;

	tmp = s->v;
	while (s->next)
	{
		s->v = s->next->v;
		s = s->next;
	}
	s->v = tmp;
}

static void	rr(t_n *s)
{
	int	tmp;
	int	tmp2;
	t_n	*t;

	t = s;
	tmp = s->v;
	while (t->next)
		t = t->next;
	s->v = t->v;
	while (s->next)
	{
		tmp2 = s->next->v;
		s->next->v = tmp;
		tmp = tmp2;
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
		r(a);
	else if (in[1] == 'b')
		r(b);
	else if (!in[2])
	{
		r(a);
		r(b);
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
