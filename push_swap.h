#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <limits.h>

typedef struct	s_n
{
	int			v;
	struct s_n	*next;
}				t_n;

/*stack operations*/

void	push(t_n *s, t_n *p);
void	swap(t_n *a, t_n *b, char c);
void	rotate(t_n *a, t_n *b, char *in);

/*auxillary functions*/

size_t	list_size(t_n *s);
int		sorted(t_n *s, size_t i, char c);
t_n		*load(int ac, char **av);

/*algorithm*/

char	**solve(t_n *a, size_t i);
char	**grow_b(t_n *a, t_n *b, int *tab, size_t i);
void	sort(t_n *a, t_n *b, size_t i, char **in);

#endif
