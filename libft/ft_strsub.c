/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csummers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 17:13:08 by csummers          #+#    #+#             */
/*   Updated: 2016/11/03 17:13:09 by csummers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	char	*result;

	if (!s)
		return (NULL);
	if ((result = ft_strnew(len)) == NULL)
		return (NULL);
	s += start;
	ptr = result;
	while (len--)
		*ptr++ = *s++;
	return (result);
}
