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

void		rotate(t_n *a, t_n *b, char *in)
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
}
