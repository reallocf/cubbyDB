/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csummers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 19:38:06 by csummers          #+#    #+#             */
/*   Updated: 2016/11/03 21:13:19 by csummers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strarrnew(size_t size)
{
	char	**ptr;
	char	**result;

	if ((result = (char**)malloc(sizeof(char*) * (size + 1))) == NULL)
		return (NULL);
	ptr = result;
	while (size--)
		*ptr++ = 0;
	*ptr = 0;
	return (result);
}
