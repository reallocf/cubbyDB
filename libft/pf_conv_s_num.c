/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conv_s_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csummers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 14:25:02 by csummers          #+#    #+#             */
/*   Updated: 2016/12/12 14:25:02 by csummers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		pf_handle_sign_early_width(t_flag *flag)
{
	if (flag->f_width && ((flag->f_plus && *flag->output != '-') ||
		(flag->f_space && *flag->output != '-') || (flag->f_prec &&
		flag->prec >= flag->output_len)))
		flag->width--;
	pf_print_width(flag);
	flag->f_width = 0;
}

static char		*pf_handle_sign(t_flag *flag)
{
	char	*new_s;

	if (flag->f_width && !flag->f_minus && !flag->f_zero &&
		(*flag->output == '-' || flag->f_plus || flag->f_space))
		pf_handle_sign_early_width(flag);
	if (*flag->output == '-')
	{
		pf_printer("-", NULL, 1);
		if (!(new_s = ft_strnew(--flag->output_len)))
			return (NULL);
		if (ft_strcpy(new_s, flag->output + 1) && flag->f_width)
			flag->width--;
		free(flag->output);
		return (new_s);
	}
	else if (flag->f_plus || flag->f_space)
	{
		pf_printer((flag->f_plus) ? "+" : " ", NULL, 1);
		if (flag->f_width)
			flag->width--;
	}
	return (flag->output);
}

static char		*pf_handle_z_llong_min(intmax_t n)
{
	char	*ret;
	char	*temp;

	if (!(ret = ft_strnew(20)))
		return (NULL);
	ret[0] = '-';
	temp = pf_imtoa_base(0, (size_t)n, 10, 0);
	ft_strcpy(ret + 1, temp);
	free(temp);
	return (ret);
}

static char		*pf_get_s_str(char len_mod, intmax_t n)
{
	if (!len_mod)
		return (pf_imtoa_base((int)n, 0, 10, 0));
	else if (len_mod == 'H')
		return (pf_imtoa_base((signed char)n, 0, 10, 0));
	else if (len_mod == 'h')
		return (pf_imtoa_base((short)n, 0, 10, 0));
	else if (len_mod == 'l')
		return (pf_imtoa_base((long)n, 0, 10, 0));
	else if (len_mod == 'L')
		return (pf_imtoa_base((long long)n, 0, 10, 0));
	else if (len_mod == 'j')
		return (pf_imtoa_base(n, 0, 10, 0));
	else if (len_mod == 'z' && n > LLONG_MIN)
		return (pf_imtoa_base(0, (size_t)n, 10, 0));
	else
		return (pf_handle_z_llong_min(n));
}

void			pf_conv_s_num(t_flag *flag, intmax_t n)
{
	if (!(flag->output = pf_get_s_str(flag->len_mod, n)))
	{
		g_ret = -1;
		return ;
	}
	flag->output_len = ft_strlen(flag->output);
	if (flag->f_zero && NUM(flag->c) && flag->f_width && flag->f_prec &&
		flag->prec < flag->width)
		flag->f_zero = 0;
	if (!(flag->output = pf_handle_sign(flag)))
	{
		g_ret = -1;
		return ;
	}
	pf_apply_width(flag);
	free(flag->output);
}
