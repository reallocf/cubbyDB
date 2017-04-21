/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_width_and_prec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csummers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 14:12:52 by csummers          #+#    #+#             */
/*   Updated: 2016/12/12 14:12:53 by csummers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		pf_prec_hash(t_flag *flag)
{
	char	*new_s;
	int		temp;

	if (flag->c == 'p' || (flag->f_hash && *(flag->output + 1)))
	{
		if ((temp = write(g_fd, flag->output, (flag->c == 'o' ? 1 : 2))) == -1
			|| !(new_s = ft_strnew((flag->output_len -= temp))))
			g_ret = -1;
		else
		{
			if ((flag->c == 'p' || flag->c == 'x' || flag->c == 'X') &&
				flag->f_width)
				flag->width -= temp;
			g_ret += temp;
			ft_strcpy(new_s, flag->output + temp);
			free(flag->output);
			flag->output = new_s;
			if (flag->c == 'o' && flag->f_prec)
				flag->prec--;
			flag->f_hash = 0;
		}
	}
}

static void		pf_apply_precision(t_flag *flag)
{
	if (NUM(flag->c) && flag->f_prec && flag->prec > flag->output_len)
	{
		HASH(flag->c) ? pf_prec_hash(flag) : 1;
		pf_print_many_chars('0', flag->prec - flag->output_len);
		if (g_ret != -1)
			pf_printer(flag->output, NULL, flag->output_len);
	}
	else if (NUM(flag->c) && ((flag->c == 'o' && flag->f_hash) ||
				(*flag->output != '0' || *(flag->output + 1))))
		pf_printer(flag->output, NULL, flag->output_len);
	else if ((STR(flag->c) || NUM(flag->c)) && flag->f_prec &&
				flag->prec < flag->output_len)
	{
		if (flag->f_wide)
			pf_printer(NULL, flag->woutput, flag->wide_dims_adj);
		else
			pf_printer(flag->output, NULL, flag->prec);
	}
	else
	{
		if (flag->f_wide)
			pf_printer(NULL, flag->woutput, flag->woutput_len);
		else
			pf_printer(flag->output, NULL, flag->output_len);
	}
}

void			pf_print_width(t_flag *flag)
{
	size_t	len;
	size_t	width;

	len = flag->output_len;
	if (STR(flag->c))
	{
		if (flag->f_wide && !flag->f_ascii)
			len = ((flag->f_prec && flag->prec - flag->wide_dims_adj < len) ?
					flag->prec - flag->wide_dims_adj : len);
		else
			len = ((flag->f_prec && flag->prec < len) ? flag->prec : len);
	}
	else
		len = ((flag->f_prec && flag->prec > len) ? flag->prec : len);
	width = flag->width + ((NUM(flag->c) && flag->c != 'p' &&
			!*(flag->output + 1) && flag->f_prec && !flag->prec &&
			!flag->f_plus && !flag->f_space && !flag->f_zero) ? 1 : 0);
	if (len < width)
		pf_print_many_chars((!flag->f_minus && flag->f_zero) ? '0' : ' ',
							width - len);
}

void			pf_apply_width(t_flag *flag)
{
	if ((flag->c == 'p' || flag->c == 'x' || flag->c == 'X') && flag->f_zero)
		pf_prec_hash(flag);
	if (flag->f_width && !flag->f_minus)
		pf_print_width(flag);
	pf_apply_precision(flag);
	if (flag->f_width && flag->f_minus)
		pf_print_width(flag);
}
