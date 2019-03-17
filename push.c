#include "push_swap.h"

static void	pop(t_n	**stack)
{
	t_n	*tmp;
	t_n	*s;
	int	c;

	s = *stack;
	tmp = s;
	c = 0;
	if (s->next)
	{
		while (s->next)
		{
			if (c)
				tmp = tmp->next;
			c = 1;
			s->v = s->next->v;
			s = s->next;
		}
		tmp->next = NULL;
	}
	else
		*stack = NULL;
}
//PROBLEM IS THAT P IS NOT MALLOCED YET. THIS CAUSES SEGFAULT BECAUSE IM TRYNA ACCESS SOMETHING THATS NOT MALLOCED YEEEEEET
void		push(t_n *s, t_n *p)
{
	int	tmp;
	int	tmp2;

	tmp = s->v;
	s->v = p->v;
	while (s)
	{
		if (!(s->next))
		{
			s->next = malloc(sizeof(t_n));
			s->next->v = tmp;
			s->next->next = NULL;
			break ;
		}
		tmp2 = s->next->v;
		s->next->v = tmp;
		tmp = tmp2;
		s = s->next;
	}
	pop(&p);
}
