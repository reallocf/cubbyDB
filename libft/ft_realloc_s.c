/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csummers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 19:52:03 by csummers          #+#    #+#             */
/*   Updated: 2016/11/03 19:52:04 by csummers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_realloc_s(char ***arr, char *s)
{
	size_t	arr_len;
	char	**a_ptr;
	char	**r_ptr;
	char	**result;

	if (!(*arr))
		arr_len = 0;
	else
		arr_len = ft_strarrlen(*arr);
	if ((result = ft_strarrnew(arr_len + 1)) == NULL)
		return (NULL);
	a_ptr = *arr;
	r_ptr = result;
	while (arr_len--)
		*r_ptr++ = *a_ptr++;
	*r_ptr++ = s;
	ft_strarrdel(arr);
	return (result);
}
