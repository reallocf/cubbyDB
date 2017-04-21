/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csummers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 23:12:10 by csummers          #+#    #+#             */
/*   Updated: 2016/11/01 23:13:09 by csummers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*dst_c;
	char	*src_c;

	dst_c = (char*)dst;
	src_c = (char*)src;
	while (n--)
	{
		*dst_c++ = *src_c++;
		if (*(src_c - 1) == c)
			return ((void*)dst_c);
	}
	return (NULL);
}
