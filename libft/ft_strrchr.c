/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csummers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 16:44:11 by csummers          #+#    #+#             */
/*   Updated: 2016/11/02 16:44:12 by csummers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char*)s + ft_strlen(s);
	while (ptr != s)
		if (*ptr-- == c)
			return (++ptr);
	if (*ptr == c)
		return (ptr);
	return (NULL);
}
