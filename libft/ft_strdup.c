/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csummers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 11:04:53 by csummers          #+#    #+#             */
/*   Updated: 2016/11/02 11:04:55 by csummers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	n;
	char	*ptr;
	char	*result;

	n = ft_strlen(s1);
	if ((result = ft_strnew(n)) == NULL)
		return (NULL);
	ptr = result;
	while (n--)
		*ptr++ = *s1++;
	return (result);
}
