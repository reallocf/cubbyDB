/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csummers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 13:10:01 by csummers          #+#    #+#             */
/*   Updated: 2016/11/03 13:10:02 by csummers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ptr;
	char	*result;

	if ((result = (char*)malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	ptr = result;
	while (size--)
		*ptr++ = '\0';
	*ptr = '\0';
	return (result);
}
