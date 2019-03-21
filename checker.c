#include "push_swap.h"

static t_n *stack_dup(t_n *s)
{
    t_n *dup;
    t_n *head;
    
    dup = malloc(sizeof(t_n));
    dup->v = s->v;
    head = dup;
    while (s->next)
    {
        dup->next = malloc(sizeof(t_n));
        dup->next->v = s->next->v;
        dup = dup->next;
        s = s->next;
    }
    dup->next = NULL;
    return (head);
}

static void	do_instructions(char **in, t_n *a)
{
	size_t	i;
	t_n		*b;

	i = -1;
	b = NULL;
	while (in[++i])
	{
		if (strequ(in[i], "pa"))
			push(&a, b);
		else if (strequ(in[i], "pb"))
			push(&b, a);
		else if (in[i][0] == 's')
			swap(a, b, in[i][1]);
		else 
			rotate(a, b, in[i]);
	}
}	

int			main(int ac, char **av)
{
	t_n		*a;
    t_n     *b;
	char	**in;
	size_t	i;

	i = 0;
	if (!(a = load(ac, av)))
	{
		ft_putendl("Error");
		return (0);
	}
    b = stack_dup(a);
	i = list_size(a);
	in = solve(a, i);
	do_instructions(in, b);
	!sorted(b, i, 'a') ? ft_putendl("KO") : ft_putendl("OK");
	ft_strdel(in);
}
