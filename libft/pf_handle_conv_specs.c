/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_conv_specs.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csummers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 14:45:18 by csummers          #+#    #+#             */
/*   Updated: 2016/12/12 14:45:18 by csummers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		pf_conv_n(t_flag *flag)
{
	if (!flag->len_mod)
		*va_arg(g_ap, int*) = g_ret;
	else if (flag->len_mod == 'H')
		*va_arg(g_ap, signed char*) = g_ret;
	else if (flag->len_mod == 'h')
		*va_arg(g_ap, short*) = g_ret;
	else if (flag->len_mod == 'l')
		*va_arg(g_ap, long*) = g_ret;
	else if (flag->len_mod == 'L')
		*va_arg(g_ap, long long*) = g_ret;
	else if (flag->len_mod == 'j')
		*va_arg(g_ap, intmax_t*) = g_ret;
	else if (flag->len_mod == 'z')
		*va_arg(g_ap, intmax_t*) = (size_t)g_ret;
}

static void		pf_read_from_va_arg(t_flag *flag)
{
	if (SN(flag->c))
		pf_conv_s_num(flag, va_arg(g_ap, intmax_t));
	else if (UN(flag->c))
		pf_conv_u_num(flag, va_arg(g_ap, uintmax_t));
	else if (flag->c == 's' && flag->len_mod == 'l')
		pf_conv_wstr(flag, va_arg(g_ap, wchar_t*));
	else if (flag->c == 's')
		pf_conv_str(flag, va_arg(g_ap, char*));
	else if (flag->c == 'c' && flag->len_mod == 'l')
		pf_conv_wchar(flag, va_arg(g_ap, wchar_t));
	else if (flag->c == 'c')
		pf_conv_char(flag, va_arg(g_ap, int));
	else if (flag->c == 'n')
		pf_conv_n(flag);
	else if (flag->c == 'w')
		g_fd = va_arg(g_ap, int);
	else
	{
		if (!(flag->output = ft_strnew(1)))
			return ;
		flag->output[0] = flag->c;
		flag->output_len = 1;
		pf_apply_width(flag);
		free(flag->output);
	}
}

void			pf_get_conv_spec(const char **format, t_flag *flag)
{
	if (!**format)
		return ;
	if ((flag->c = *(*format)++) && CAP(flag->c))
	{
		flag->c = ft_tolower(flag->c);
		flag->len_mod = 'l';
	}
	else if (flag->c == 'p')
		flag->len_mod = 'l';
	pf_read_from_va_arg(flag);
}
