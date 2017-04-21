/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csummers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:57:49 by csummers          #+#    #+#             */
/*   Updated: 2016/12/12 13:57:50 by csummers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		pf_print_the_wchar(char *buff)
{
	int		len;

	if ((len = write(g_fd, buff, ft_strlen(buff))) == -1)
		g_ret = -1;
	else
		g_ret += len;
}

static void		pf_putwchar(wchar_t c)
{
	unsigned char	*buff;

	buff = (unsigned char*)ft_strnew(4);
	if (c <= 0x7F)
		buff[0] = (unsigned char)c;
	else if (c <= 0x7FF)
	{
		buff[0] = (unsigned char)((c >> 6) | 0xC0);
		buff[1] = (unsigned char)((c & 0x3F) | 0x80);
	}
	else if (c <= 0xFFFF)
	{
		buff[0] = (unsigned char)((c >> 12) | 0xE0);
		buff[1] = (unsigned char)(((c >> 6) & 0x3F) | 0x80);
		buff[2] = (unsigned char)((c & 0x3F) | 0x80);
	}
	else if (c <= 0x10FFFF)
	{
		buff[0] = (unsigned char)((c >> 18) | 0xF0);
		buff[1] = (unsigned char)(((c >> 12) & 0x3F) | 0x80);
		buff[2] = (unsigned char)(((c >> 6) & 0x3F) | 0x80);
		buff[3] = (unsigned char)((c & 0x3F) | 0x80);
	}
	pf_print_the_wchar((char*)buff);
	free(buff);
}

void			pf_printer(char *output, wchar_t *woutput, size_t len)
{
	size_t	i;
	int		temp;

	if (output)
	{
		if ((temp = write(g_fd, output, len)) == -1)
			g_ret = -1;
		else
			g_ret += temp;
	}
	else
	{
		i = 0;
		while (i < len)
		{
			pf_putwchar(*woutput++);
			i++;
		}
	}
}

void			pf_print_many_chars(char c, size_t n)
{
	char	*s;
	int		temp;

	if (!(s = ft_strnew(n)))
	{
		g_ret = -1;
		return ;
	}
	ft_memset(s, c, n);
	if ((temp = write(g_fd, s, n)) == -1)
		g_ret = -1;
	else
		g_ret += temp;
	free(s);
}
