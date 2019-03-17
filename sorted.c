#include "push_swap.h"

int	sorted(t_n *s, size_t i, char c)
{
	if (list_size(s) != i)
		return (0);
	if (c == 'a')
		while (s)
		{
			if (s->next && s->v > s->next->v)
				return (0);
			s = s->next;
		}
	else
		while (s)
		{
			if (s->next && s->v < s->next->v)
				return (0);
			s = s->next;
		}
	return (1);
}
