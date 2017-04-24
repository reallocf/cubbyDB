#include "cubby.h"

int	main(void)
{
    t_cubby	*cubby;

    cubby = cubby_init();
    if (!cubby)
    {
	ft_printf("%wcubby init error\n", 2);
	return (1);
    }
    cubby_push(cubby, "first key", "Does it persist?");
    ft_printf("value: %s\n", cubby_pull(cubby, "first key"));
    cubby_close(&cubby);
    return (0);
}
