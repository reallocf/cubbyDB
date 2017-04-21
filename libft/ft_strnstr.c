/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csummers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 22:18:21 by csummers          #+#    #+#             */
/*   Updated: 2016/11/02 22:18:22 by csummers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*lil_ptr;
	const char	*big_ptr;
	size_t		lil_len;
	size_t		big_len;

	if (*little == '\0')
		return ((char*)big);
	lil_len = ft_strlen(little);
	big_len = ft_strlen(big);
	while (len-- >= lil_len && big_len-- >= lil_len)
	{
		lil_ptr = little;
		big_ptr = big;
		while (*lil_ptr++ == *big_ptr++)
		{
			if (*lil_ptr == '\0')
				return ((char*)big);
		}
		big++;
	}
	return (NULL);
}
