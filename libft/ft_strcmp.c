/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csummers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 11:57:18 by csummers          #+#    #+#             */
/*   Updated: 2016/11/03 11:57:18 by csummers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*u_s1;
	unsigned char	*u_s2;

	u_s1 = (unsigned char*)s1;
	u_s2 = (unsigned char*)s2;
	while (*u_s1 == *u_s2 && *u_s1 && *u_s2)
	{
		u_s1++;
		u_s2++;
	}
	return (*u_s1 - *u_s2);
}
