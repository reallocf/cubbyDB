/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csummers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 22:24:14 by csummers          #+#    #+#             */
/*   Updated: 2016/11/01 22:24:15 by csummers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*c_dst;
	char	*c_src;

	c_dst = (char*)dst;
	c_src = (char*)src;
	while (n--)
		*c_dst++ = *c_src++;
	return (dst);
}
