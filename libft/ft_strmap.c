/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csummers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 16:42:47 by csummers          #+#    #+#             */
/*   Updated: 2016/11/03 16:42:47 by csummers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	s_len;
	char	*ptr;
	char	*result;

	if (!s || !f)
		return (NULL);
	s_len = ft_strlen(s);
	if ((result = ft_strnew(s_len)) == NULL)
		return (NULL);
	ptr = result;
	while (s_len--)
		*ptr++ = f(*s++);
	return (result);
}
