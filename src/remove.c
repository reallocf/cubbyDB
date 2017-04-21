#include "cubby.h"

void		delete_slot(t_elem **slot)
{
    if (!slot || !*slot)
	return ;
    ft_strdel(&((*slot)->key));
    ft_strdel(&((*slot)->val));
    free(*slot);
    *slot = NULL;
}

static int	find_and_remove(t_cubby *cubby, char *key, t_elem *slot)
{
    t_elem	*temp;

    if (ft_strequ(slot->key, key))
    {
	if (ft_printf("%w=%s\n", cubby->fd, key) == -1)
	    return (-1);
	cubby->slot = slot->next;
	delete_slot(&slot);
	return (0);
    }
    while (slot->next)
    {
	if (ft_strequ(slot->next->key, key))
	{
	    if (ft_printf("%w=%s\n", cubby->fd, key) == -1)
		return (-1);
	    temp = slot->next;
	    slot->next = slot->next->next;
	    delete_del(&temp);
	    return (0);
	}
	slot = slot->next;
    }
    return (-1);
}

int		cubby_remove(t_cubby *cubby, char *key)
{
    unsigned int	hashed_key;

    if (!cubby || !key)
	return (-1);
    hashed_key = hash(key);
    if (cubby->slot[hashed_key])
	return (find_and_remove(cubby, key, cubby->slot[hashed_key]));
    else
	return (-1);
}
