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

static void	handle_null_stack(t_n **stack, int v)
{
	t_n	*s;

	*stack = malloc(sizeof(t_n));
	s = *stack;
	s->v = v;
	s->next = malloc(sizeof(t_n));
	s->next = NULL;
}

static void	regular_push(t_n **stack, int v)
{
	t_n	*s;
	int	tmp;
	int	tmp2;

	s = *stack;
	tmp = s->v;
	s->v = v;
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
}

void		push(t_n **stack, t_n *p)
{
	!*stack ? handle_null_stack(stack, p->v) : regular_push(stack, p->v);
	pop(&p);
}
