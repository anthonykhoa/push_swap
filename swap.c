#include "push_swap.h"

void	swap(t_n *a, t_n *b, char c)
{
	int	tmp;

	if (c == 'a')
	{
		tmp = a->v;
		a->v = a->next->v;
		a->next->v = tmp;
	}
	else if (c == 'b')
	{
		tmp = b->v;
		b->v = b->next->v;
		b->next->v = tmp;
	}
	else
	{
		tmp = a->v;
		a->v = a->next->v;
		a->next->v = tmp;
		tmp = b->v;
		b->v = b->next->v;
		b->next->v = tmp;
	}
}
