/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conv_u_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csummers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 14:30:02 by csummers          #+#    #+#             */
/*   Updated: 2016/12/12 14:30:02 by csummers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int				handle_hash(t_flag *flag, uintmax_t n)
{
	char	*new_s;
	int		adj;

	if (flag->c == 'p' || (flag->f_hash && HASH(flag->c)))
	{
		if (n == 0 && (flag->c == 'x' || flag->c == 'X'))
			return (1);
		adj = (flag->c == 'o') ? 1 : 2;
		if (!(new_s = ft_strnew(flag->output_len + adj)))
			return (0);
		new_s[0] = '0';
		if (flag->c == 'x' || flag->c == 'p')
			new_s[1] = 'x';
		else if (flag->c == 'X')
			new_s[1] = 'X';
		if (n != 0 || (flag->c == 'p' && (!flag->f_prec ||
			(flag->f_prec && flag->prec != 0))))
			ft_strcpy(new_s + adj, flag->output);
		else
			flag->output_len--;
		free(flag->output);
		flag->output = new_s;
		flag->output_len += adj;
	}
	return (1);
}

static char				*pf_get_u_str(t_flag *flag, uintmax_t n,
										unsigned int base, int cap)
{
	if (!flag->len_mod)
		return (pf_imtoa_base(0, (unsigned int)n, base, cap));
	else if (flag->len_mod == 'H')
		return (pf_imtoa_base(0, (unsigned char)n, base, cap));
	else if (flag->len_mod == 'h')
		return (pf_imtoa_base(0, (unsigned short)n, base, cap));
	else if (flag->len_mod == 'l')
		return (pf_imtoa_base(0, (unsigned long)n, base, cap));
	else if (flag->len_mod == 'L')
		return (pf_imtoa_base(0, (unsigned long long)n, base, cap));
	else if (flag->len_mod == 'j')
		return (pf_imtoa_base(0, n, base, cap));
	else
		return (pf_imtoa_base(0, (size_t)n, base, cap));
}

static unsigned int		pf_get_base(t_flag *flag)
{
	unsigned int	base;

	base = 10;
	if (flag->c == 'o')
		base = 8;
	else if (flag->c == 'x' || flag->c == 'X' || flag->c == 'p')
		base = 16;
	else if (flag->c == 'b')
		base = 2;
	return (base);
}

void					pf_conv_u_num(t_flag *flag, uintmax_t n)
{
	flag->output = pf_get_u_str(flag, n, pf_get_base(flag),
								(flag->c == 'X') ? 1 : 0);
	if (!flag->output)
	{
		g_ret = -1;
		return ;
	}
	if (flag->f_zero && NUM(flag->c) && flag->f_width && flag->f_prec &&
		flag->prec < flag->width)
		flag->f_zero = 0;
	flag->output_len = ft_strlen(flag->output);
	if (!(handle_hash(flag, n)))
	{
		g_ret = -1;
		free(flag->output);
		return ;
	}
	pf_apply_width(flag);
	free(flag->output);
}
