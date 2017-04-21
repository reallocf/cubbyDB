/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csummers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 16:31:36 by csummers          #+#    #+#             */
/*   Updated: 2016/11/17 16:31:37 by csummers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*copy_until_n(char **s, char *buff, size_t n)
{
	size_t	s_len;
	char	*res;

	if (!*s)
		s_len = 0;
	else
		s_len = ft_strlen(*s);
	if (!(res = ft_strnew(s_len + n)))
		return (NULL);
	if (*s)
		ft_strcpy(res, *s);
	ft_strncat(res, buff, n);
	free(*s);
	return (res);
}

static t_buff	*read_into(t_buff **buff, int fd)
{
	long long	read_size;
	char		read_s[BUFF_SIZE + 1];

	if (!buff[fd])
	{
		if (!(buff[fd] = (t_buff*)malloc(sizeof(t_buff))))
			return (NULL);
		buff[fd]->old_r_s = 0;
	}
	buff[fd]->s = NULL;
	while ((read_size = read(fd, read_s, BUFF_SIZE)))
	{
		if (read_size == -1)
			return (NULL);
		read_s[read_size] = '\0';
		buff[fd]->s = copy_until_n(&buff[fd]->s, read_s, read_size);
		buff[fd]->old_r_s = read_size;
		if (ft_strchr(buff[fd]->s, 10))
			break ;
	}
	buff[fd]->is_s = (buff[fd]->s) ? 1 : 0;
	buff[fd]->is_f = (read_size && read_size == buff[fd]->old_r_s) ? 1 : 0;
	buff[fd]->old_r_s = read_size;
	buff[fd]->p = buff[fd]->s;
	return (buff[fd]);
}

static int		clear(t_buff **buff, int fd)
{
	free(buff[fd]->s);
	buff[fd]->s = NULL;
	buff[fd]->p = buff[fd]->s;
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_buff	*buff[MAX_FD];
	char			*nl;

	if (!line || fd < 0 || fd >= MAX_FD || !(*line = ft_strnew(0)))
		return (-1);
	while (1)
	{
		if ((!buff[fd] || !buff[fd]->is_s) && !read_into(buff, fd))
			return (-1);
		if (!buff[fd]->is_s && !buff[fd]->is_f && clear(buff, fd))
			return ((**line) ? 1 : 0);
		if ((nl = ft_strchr(buff[fd]->p, 10)))
		{
			if (!(*line = copy_until_n(line, buff[fd]->p, nl - buff[fd]->p)))
				return (-1);
			if (!*(buff[fd]->p = nl + 1))
				buff[fd]->is_s = 0;
			return (1);
		}
		if (!(*line = copy_until_n(line, buff[fd]->p, ft_strlen(buff[fd]->p))))
			return (-1);
		if (!(buff[fd]->is_s = 0) && !buff[fd]->is_f)
			return (1);
	}
}
