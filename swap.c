#include "push_swap.h"

static void	perform_swap(t_n *s)
{
	int v;
	int n;

	v = s->v;
	n = s->n;
	s->v = s->next->v;
	s->n = s->next->n;
	s->next->v = v;
	s->next->n = n;
}

void		swap(t_n *a, t_n *b, char c, int x)
{
	if (c == 'a')
	{
		perform_swap(a);
		if (x)
			*(g_in + g_i++) = "sa";
	}
	else if (c == 'b')
	{
		perform_swap(b);
		if (x)
			*(g_in + g_i++) = "sb";
	}
	else
	{
		perform_swap(a);
		perform_swap(b);
		if (x)
			*(g_in + g_i++) = "ss";
	}
}
