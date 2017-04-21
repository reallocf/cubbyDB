#include "cubby.h"

static t_cubby	*new_cubby(void)
{
    t_cubby	*cubby;

    if (!(cubby = (cubby*)malloc(sizeof(cubby))))
	return (NULL);
    if (!(cubby->slot = (elem**)malloc(sizeof(elem*) * SLOT_COUNT)))
	return (NULL);
    for (int i = 0; i < SLOT_COUNT; i++)
	cubby->slot[i] = NULL;
    return (cubby);
}

static void	load_data(t_cubby *cubby)
{
    int			fd;
    char		*line;
    char		**split;
    unsigned int	key_hash;

    fd = open("~.cubbyDB", O_RDONLY | O_NONBLOCK);
    while (getnextline(fd, &line) > 0)
    {
	split = ft_strsplit(line, '=');
	if (line[0] == '=')
	    cubby_remove(cubby, split[0]);
	else if (split[1])
	    cubby_pusher(cubby, split[0], split[1], 0);
	else
	    cubby_pusher(cubby, split[0], "", 0);
	ft_strdel(&line);
    }
    close(fd);
}

t_cubby		*cubby_init(void)
{
    t_cubby	*cubby;

    if (!(cubby = new_cubby()))
	return (NULL);
    if (access("~/.cubbyDB", F_OK) != -1)
	load_data(cubby);
    else
	errno = 0;
    cubby->fd = open("~/.cubbyDB", O_WRONLY | O_APPEND | O_NONBLOCK | O_CREATE,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (errno != 0)
	return (NULL);
    return (cubby);
}
