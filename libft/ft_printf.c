/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csummers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 22:15:54 by csummers          #+#    #+#             */
/*   Updated: 2016/11/27 22:15:55 by csummers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Completed Bonuses:
** handles standard n conversion
** handles standard * flag for width and precision
** added b conversion to convert unsigned numbers to binary
** added w conversion to change fd to print to a file after the conversion
*/

static int		pf_initialize_flag(const char **format)
{
	t_flag	*flag;

	if (!(flag = (t_flag*)malloc(sizeof(t_flag))))
		return ((g_ret = -1));
	flag->f_width = 0;
	flag->width = 0;
	flag->f_prec = 0;
	flag->prec = 0;
	flag->f_wide = 0;
	flag->f_minus = 0;
	flag->f_plus = 0;
	flag->f_space = 0;
	flag->f_zero = 0;
	flag->f_hash = 0;
	flag->len_mod = 0;
	while (F(**format) || ft_isdigit(**format) || **format == '*' ||
			**format == '.' || L(**format))
		pf_get_flag_info(format, flag);
	pf_get_conv_spec(format, flag);
	free(flag);
	return (1);
}

static void		pf_start_to_write(const char **format)
{
	char	*perc_loc;
	int		temp;

	while (**format)
	{
		if (!(perc_loc = ft_strchr(*format, '%')))
		{
			temp = g_ret;
			pf_printer((char*)*format, NULL, ft_strlen(*format));
			if (g_ret == -1)
				return ;
			*format += g_ret - temp;
		}
		else
		{
			temp = g_ret;
			pf_printer((char*)*format, NULL, perc_loc - *format);
			if (g_ret == -1)
				return ;
			*format += g_ret - temp + 1;
			pf_initialize_flag(format);
			if (g_ret == -1)
				return ;
		}
	}
}

int				ft_printf(const char *format, ...)
{
	g_ret = 0;
	g_fd = 1;
	va_start(g_ap, format);
	pf_start_to_write(&format);
	va_end(g_ap);
	return (g_ret);
}
