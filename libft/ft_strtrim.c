/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csummers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 17:51:04 by csummers          #+#    #+#             */
/*   Updated: 2016/11/03 17:51:05 by csummers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char const	*s_end;
	char		*result_ptr;
	char		*result;

	if (!s)
		return (NULL);
	s_end = s + ft_strlen(s) - 1;
	while ((*s == ' ' || *s == '\t' || *s == '\n') && *s != '\0')
		s++;
	if (*s == '\0')
		return (result = ft_strnew(0));
	while (*s_end == ' ' || *s_end == '\t' || *s_end == '\n')
		s_end--;
	if ((result = ft_strnew(s_end - s + 1)) == NULL)
		return (NULL);
	result_ptr = result;
	while (s != s_end + 1)
		*(result_ptr++) = *(s++);
	return (result);
}
