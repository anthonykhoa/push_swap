/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base16x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 12:48:29 by anttran           #+#    #+#             */
/*   Updated: 2019/02/27 18:21:00 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*base16x(uintmax_t n)
{
	char	*str;
	char	*x;
	char	*tmp;
	int		i;

	i = 0;
	if (!n)
		return (ft_strdup("0"));
	str = malloc(30);
	x = "0123456789abcdef";
	while (n)
	{
		str[i++] = x[n & 15];
		n = n >> 4;
	}
	str[i] = '\0';
	tmp = str;
	str = rev_str(tmp);
	free(tmp);
	return (str);
}
