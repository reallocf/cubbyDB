/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_flag_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csummers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 14:49:40 by csummers          #+#    #+#             */
/*   Updated: 2016/12/12 14:49:41 by csummers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		pf_get_length_spec(const char **format, t_flag *flag)
{
	if (**format == 'h' && flag->len_mod < 'h' && flag->len_mod != 'L')
	{
		flag->len_mod = *(*format)++;
		if (**format == 'h')
		{
			flag->len_mod = 'H';
			(*format)++;
		}
	}
	else if (**format == 'l' && flag->len_mod < 'l' && flag->len_mod != 'j')
	{
		flag->len_mod = *(*format)++;
		if (**format == 'l')
		{
			flag->len_mod = 'L';
			(*format)++;
		}
	}
	else if (**format == 'j' && (flag->len_mod < 'j' ||
									flag->len_mod == 'l'))
		flag->len_mod = *(*format)++;
	else if (**format == 'z')
		flag->len_mod = *(*format)++;
	else
		(*format)++;
}

static size_t	pf_abs(t_flag *flag, int n, char c)
{
	if (n < 0 && c == 'w')
	{
		flag->f_minus = 1;
		return (n * -1);
	}
	else if (n < 0)
	{
		flag->f_prec = 0;
		return (0);
	}
	return (n);
}

static void		pf_get_prec(const char **format, t_flag *flag)
{
	flag->f_prec = 1;
	(*format)++;
	flag->prec = ft_atoi(*format);
	while (ft_isdigit(**format))
		(*format)++;
	if (**format == '*' && (*format)++)
		flag->prec = pf_abs(flag, va_arg(g_ap, int), 'p');
}

static void		pf_get_width(const char **format, t_flag *flag)
{
	while (ft_isdigit(**format) || **format == '*')
	{
		if (ft_isdigit(**format))
		{
			flag->f_width = 1;
			flag->width = ft_atoi(*format);
			while (ft_isdigit(**format))
				(*format)++;
		}
		if (**format == '*')
		{
			flag->f_width = 1;
			flag->width = pf_abs(flag, va_arg(g_ap, int), 'w');
			(*format)++;
		}
	}
}

void			pf_get_flag_info(const char **format, t_flag *flag)
{
	if (F(**format))
	{
		if (**format == '-')
			flag->f_minus = 1;
		else if (**format == '+')
			flag->f_plus = 1;
		else if (**format == ' ')
			flag->f_space = 1;
		else if (**format == '0')
			flag->f_zero = 1;
		else if (**format == '#')
			flag->f_hash = 1;
		(*format)++;
	}
	else if (ft_isdigit(**format) || **format == '*')
		pf_get_width(format, flag);
	else if (**format == '.')
		pf_get_prec(format, flag);
	else
		pf_get_length_spec(format, flag);
}
