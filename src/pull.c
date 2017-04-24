#include "cubby.h"

char	*cubby_pull(t_cubby *cubby, char *key)
{
    unsigned int	key_hash;
    t_elem		*slot;

    if (!cubby || !key || !*key)
	return (NULL);
    key_hash = hash(key);
    slot = cubby->slot[key_hash];
    while (slot)
    {
	if (ft_strequ(slot->key, key))
	    return (slot->val);
	slot = slot->next;
    }
    return (NULL);
}
