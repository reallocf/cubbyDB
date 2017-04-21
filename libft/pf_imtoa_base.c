/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_imtoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csummers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:57:13 by csummers          #+#    #+#             */
/*   Updated: 2016/12/12 13:57:15 by csummers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	char_convert(int c, int cap)
{
	if (c < 10)
		return (c + '0');
	return ((cap) ? c - 10 + 'A' : c - 10 + 'a');
}

static char	*f_d(int digasst, uintmax_t value, unsigned int base, int c)
{
	char		*res;
	char		*res_ptr;

	if (!(res = ft_strnew(digasst + ((c == -1) ? 1 : 0))))
		return (NULL);
	res_ptr = res;
	if (c == -1)
		*res_ptr++ = '-';
	while (digasst)
	{
		*res_ptr++ = char_convert(value / ft_pow(base, digasst), c);
		value = value % ft_pow(base, digasst);
		digasst--;
	}
	*res_ptr++ = char_convert(value / ft_pow(base, digasst), c);
	*res_ptr = '\0';
	return (res);
}

char		*pf_imtoa_base(intmax_t im, uintmax_t uim, unsigned int b, int c)
{
	char		*res;
	size_t		digasst;

	if (!im && !uim)
	{
		if (!(res = ft_strnew(1)))
			return (NULL);
		res[0] = '0';
		return (res);
	}
	if (im < 0)
	{
		if (b == 10)
			c = -1;
		uim = im * -1;
	}
	else if (!uim)
		uim = im;
	digasst = 0;
	while (uim / ft_pow(b, digasst) >= b)
		digasst++;
	return (f_d(digasst, uim, b, c));
}
