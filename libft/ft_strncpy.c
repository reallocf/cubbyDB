/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csummers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 11:36:50 by csummers          #+#    #+#             */
/*   Updated: 2016/11/02 11:36:52 by csummers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*ptr;

	ptr = dst;
	while (len && *src)
	{
		*ptr++ = *src++;
		len--;
	}
	while (len--)
		*ptr++ = '\0';
	return (dst);
}
