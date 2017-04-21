/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csummers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 16:18:01 by csummers          #+#    #+#             */
/*   Updated: 2016/11/03 16:18:02 by csummers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;
	size_t	s_len;

	if (!s || !f)
		return ;
	s_len = ft_strlen(s);
	i = 0;
	while (i < s_len)
	{
		f(i, &(s[i]));
		i++;
	}
}
