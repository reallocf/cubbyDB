/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csummers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 10:11:23 by csummers          #+#    #+#             */
/*   Updated: 2016/11/02 10:11:24 by csummers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	c_char;
	char	*c_src;

	c_char = (char)c;
	c_src = (char*)s;
	while (n--)
		if (*c_src++ == c_char)
			return ((void*)(--c_src));
	return (NULL);
}
