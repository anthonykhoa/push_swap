#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <limits.h>
# include <stdio.h>

typedef struct	s_n
{
	int			v;
	struct s_n	*next;
}				t_n;

/*stack operations*/

void	push(t_n **stack, t_n *p);
void	swap(t_n *a, t_n *b, char c);
void	rotate(t_n *a, t_n *b, char *in);

/*auxillary functions*/

int		list_size(t_n *s);
int		sorted(t_n *s, int i, char c);
t_n		*load(int ac, char **av);
int		*rem_int_arr_element(int *arr, int c, int v);

/*algorithm*/

char	**solve(t_n *a, int i);
char	**grow_b(t_n *a, t_n **b, int *tab, int i);
void	sort(t_n *a, t_n *b, int i, char **in);

#endif
