/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csummers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 16:58:22 by csummers          #+#    #+#             */
/*   Updated: 2016/11/03 16:58:22 by csummers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	s_len;
	char	*result;

	if (!s || !f)
		return (NULL);
	s_len = ft_strlen(s);
	if ((result = ft_strnew(s_len)) == NULL)
		return (NULL);
	i = 0;
	while (i < s_len)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	return (result);
}
