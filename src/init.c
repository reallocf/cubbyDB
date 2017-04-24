#include "cubby.h"

static t_cubby	*new_cubby(void)
{
    t_cubby	*cubby;

    if (!(cubby = (t_cubby*)malloc(sizeof(t_cubby))))
	return (NULL);
    if (!(cubby->slot = (t_elem**)malloc(sizeof(t_elem*) * SLOT_COUNT)))
	return (NULL);
    for (int i = 0; i < SLOT_COUNT; i++)
	cubby->slot[i] = NULL;
    return (cubby);
}

static void	load_data(t_cubby *cubby)
{
    char		*line;
    char		**split;

    cubby->fd = open(".cubbyDB", O_RDWR | O_NONBLOCK | O_APPEND);
    while (get_next_line(cubby->fd, &line) > 0)
    {
	split = ft_strsplit(line, '=');
	if (line[0] == '=')
	    cubby_remover(cubby, split[0], 0);
	else if (split[1])
	    cubby_pusher(cubby, split[0], split[1], 0);
	else
	    cubby_pusher(cubby, split[0], "", 0);
	ft_strdel(&line);
    }
}

t_cubby		*cubby_init(void)
{
    t_cubby	*cubby;

    if (!(cubby = new_cubby()))
	return (NULL);
    if (access(".cubbyDB", F_OK) != -1)
	load_data(cubby);
    else
    {
	errno = 0;
	cubby->fd = open(".cubbyDB", O_WRONLY | O_NONBLOCK | O_CREAT, 0644);
    }
    if (errno != 0)
	return (NULL);
    return (cubby);
}
