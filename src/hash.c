#include "cubby.h"

unsigned int	hash(char *str)
{
    unsigned int	ret;

    ret = 5381;
    while (str)
	ret = ((ret << 5) + ret) + *str++;
    return (ret % SLOT_COUNT);
}
