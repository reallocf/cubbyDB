/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csummers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 12:10:00 by csummers          #+#    #+#             */
/*   Updated: 2016/11/03 12:10:01 by csummers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*u_s1;
	unsigned char	*u_s2;

	u_s1 = (unsigned char*)s1;
	u_s2 = (unsigned char*)s2;
	if (!n)
		return (0);
	while (*u_s1 == *u_s2 && *u_s1 && *u_s2 && --n)
	{
		u_s1++;
		u_s2++;
	}
	return (*u_s1 - *u_s2);
}
