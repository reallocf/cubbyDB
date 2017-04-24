#include "cubby.h"

void	cubby_close(t_cubby **cubby)
{
    for (int i = 0; i < SLOT_COUNT; i++)
	delete_slot((*cubby)->slot + i);
    free((*cubby)->slot);
    (*cubby)->slot = NULL;
    free(*cubby);
    *cubby = NULL;
}
