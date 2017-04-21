/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csummers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 09:47:45 by csummers          #+#    #+#             */
/*   Updated: 2016/11/02 09:47:47 by csummers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*c_dst;
	char	*c_src;

	if (src > dst && len != 0)
	{
		c_dst = (char*)dst;
		c_src = (char*)src;
		while (len--)
			*c_dst++ = *c_src++;
	}
	else if (src < dst && len != 0)
	{
		c_dst = (char*)dst + len - 1;
		c_src = (char*)src + len - 1;
		while (len--)
			*c_dst-- = *c_src--;
	}
	return (dst);
}
