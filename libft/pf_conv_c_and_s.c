/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conv_c_and_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csummers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 14:36:23 by csummers          #+#    #+#             */
/*   Updated: 2016/12/12 14:36:26 by csummers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		pf_char_zero(t_flag *flag)
{
	flag->output_len = 1;
	if (flag->f_prec && flag->f_zero)
		flag->prec--;
	if (flag->f_width && !flag->f_minus)
		pf_print_width(flag);
	pf_printer("\0", NULL, 1);
	if (flag->f_width && flag->f_minus)
		pf_print_width(flag);
}

void			pf_conv_char(t_flag *flag, int n)
{
	if (n == 0)
	{
		pf_char_zero(flag);
		return ;
	}
	if (!(flag->output = ft_strnew(1)))
	{
		g_ret = -1;
		return ;
	}
	flag->output[0] = n;
	flag->output_len = 1;
	pf_apply_width(flag);
}

void			pf_conv_wchar(t_flag *flag, wchar_t n)
{
	if (n == 0)
	{
		pf_char_zero(flag);
		return ;
	}
	flag->f_wide = 1;
	if (!(flag->woutput = (wchar_t*)malloc(sizeof(wchar_t) * 2)))
	{
		g_ret = -1;
		return ;
	}
	flag->woutput[0] = n;
	flag->woutput[1] = '\0';
	flag->output_len = pf_wstrlen(flag->woutput);
	flag->woutput_len = 1;
	flag->wide_dims_adj = pf_wide_dims_adj(flag);
	flag->f_ascii = pf_is_ascii(flag->woutput);
	pf_apply_width(flag);
	free(flag->woutput);
}

void			pf_conv_str(t_flag *flag, char *s)
{
	if (s)
	{
		flag->output = s;
		flag->output_len = ft_strlen(s);
		pf_apply_width(flag);
	}
	else
	{
		flag->output = "(null)";
		flag->output_len = 6;
		pf_apply_width(flag);
	}
}

void			pf_conv_wstr(t_flag *flag, wchar_t *s)
{
	if (s)
	{
		flag->f_wide = 1;
		flag->woutput = s;
		flag->output_len = pf_wstrlen(flag->woutput);
		flag->woutput_len = pf_wlen(flag->woutput);
		flag->wide_dims_adj = pf_wide_dims_adj(flag);
		flag->f_ascii = pf_is_ascii(flag->woutput);
		pf_apply_width(flag);
	}
	else
	{
		flag->output = "(null)";
		flag->output_len = 6;
		pf_apply_width(flag);
	}
}
