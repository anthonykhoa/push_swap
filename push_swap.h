#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <limits.h>

typedef struct	s_n
{
	int			v;
	int			n;
	struct s_n	*next;
}				t_n;

int				g_i;
char			**g_in;

void			push(t_n **stack, t_n **p, int c, int x);
void			swap(t_n *a, t_n *b, char c, int x);
void			rotate(t_n *a, t_n *b, char *in, int x);
int				list_size(t_n *s);
int				sorted(t_n *s, int i, char c);
t_n             *stack_dup(t_n *s);
void			rem_int_arr_element(int **arr, int c, int v);
char			**cut_down(void);
int				has_node(t_n *s, int n);
int             smallest_node_element(t_n *s, int n);
int				last_value(t_n *s);
int				last_node_value(t_n *s);
int				largest_node_element(t_n *s, int n);
int				largest_node(t_n *s);
t_n				*load(int ac, char **av);
void			solve(t_n *a, int i);
void			grow_small_b(t_n *a, t_n **b, int **tab, int i);
void			bubble_sort(t_n *a, t_n *b, int i);
void			merge_sort(t_n *a, t_n *b, int size);
void			rank_nodes(t_n *a, t_n *b, int size);
void 		    sorted_nodes_check(t_n **a, t_n **b, int size);

#endif
