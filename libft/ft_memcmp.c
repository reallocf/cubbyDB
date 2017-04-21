/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csummers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 10:39:04 by csummers          #+#    #+#             */
/*   Updated: 2016/11/02 10:39:07 by csummers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*c_s1;
	unsigned char	*c_s2;

	c_s1 = (unsigned char*)s1;
	c_s2 = (unsigned char*)s2;
	while (n--)
		if (*c_s1++ != *c_s2++)
			return (*--c_s1 - *--c_s2);
	return (0);
}
