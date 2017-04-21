/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csummers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 12:23:23 by csummers          #+#    #+#             */
/*   Updated: 2016/11/03 12:23:24 by csummers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*ptr;
	void	*result;

	if ((result = malloc(size)) == NULL)
		return (NULL);
	ptr = (char*)result;
	while (size--)
		*ptr++ = 0;
	return (result);
}
