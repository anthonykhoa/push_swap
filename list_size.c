#include "push_swap.h"

size_t	list_size(t_n *s)
{
	size_t	i;

	i = 0;
	while (s)
	{
		i++;
		s = s->next;
	}
	return (i);
}
