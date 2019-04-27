/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 21:12:20 by anttran           #+#    #+#             */
/*   Updated: 2019/04/13 21:12:21 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
int				g_v;
int				g_plz;
char			**g_in;

void			push(t_n **stack, t_n **p, int c, int x);
void			swap(t_n *a, t_n *b, char c, int x);
void			rotate(t_n *a, t_n *b, char *in, int x);
int				list_size(t_n *s);
int				sorted(t_n *s, int i);
int             str_size(char **str);
char            **stupid_string(char **str);
char			**cut_down(void);
int				has_node(t_n *s, int n);
int				last_value(t_n *s);
int				last_node_value(t_n *s);
int				largest_node_element(t_n *s, int n);
void			print_stacks(t_n *a, t_n *b, char *in, int i);
int				largest_node(t_n *s);
t_n				*load(int ac, char **av);
void			solve(t_n *a, int i);
void			merge_sort(t_n *a, t_n *b, int size);
void			pre_msort(t_n *a, t_n *b);
void			rank_nodes(t_n *a, t_n *b, int size);

#endif
