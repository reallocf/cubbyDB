/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csummers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:25:04 by csummers          #+#    #+#             */
/*   Updated: 2016/11/03 18:25:05 by csummers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	char	*tempstr;
	char	**result;

	if (!s || (result = ft_strarrnew(0)) == NULL)
		return (NULL);
	while (*s)
	{
		if ((tempstr = ft_strnew(0)) == NULL)
			return (NULL);
		while (*s == c)
			s++;
		if (!*s)
			break ;
		while (*s != c && *s)
			if ((tempstr = ft_realloc_c(&tempstr, *s++)) == NULL)
				return (NULL);
		if (*tempstr)
			if ((result = ft_realloc_s(&result, tempstr)) == NULL)
				return (NULL);
		if (*s)
			s++;
	}
	return (result);
}
