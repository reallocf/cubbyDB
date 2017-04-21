#include "cubby.h"

static t_elem	*new_elem(char *key, char *val)
{
    t_elem	*ret;

    ret = (t_elem*)malloc(sizeof(t_elem));
    ret->key = ft_strdup(key);
    ret->val = ft_strdup(val);
    ret->next = NULL;
    return (ret);
}

static int	update_or_chain(t_cubby *cubby, char *key, char *val)
{
    if (ft_strequ(slot->key, key))
    {
	slot->val = ft_strdup(val);
	return ;
    }
    while (slot->next)
    {
	if (ft_strequ(slot->next->key, key))
	{
	    slot->next->val = ft_strdup(val);
	    return ;
	}
    }
    slot->next = new_elem(key, val);
}

int	cubby_pusher(t_cubby *cubby, char *key, char *val, int persist)
{
    unsigned int	key_hash;

    if (!cubby || !key)
	return (-1);
    if (ft_strchr(key, '=') || ft_strchr(val, '='))
	return (-1);
    key_hash = hash(key);
    errno = 0;
    if (cubby->slot[key_hash])
	update_or_chain(cubby, key, val, cubby->slot[key_hash]);
    else
	cubby->slot[key_hash] = new_elem(key, val);
    if (persist)
	if (ft_printf("%w%s=%s\n", cubby->fd, key, val) == -1)
	    return (-1);
    if (errno != 0)
	return (-1);
    return (0);
}

int	cubby_push(t_cubby *cubby, char *key, char *val)
{
    return (cubby_pusher(cubby, key, val, 1));
}
