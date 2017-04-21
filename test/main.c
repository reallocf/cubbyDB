#include "cubbyDB.h"

int	main(void)
{
    t_cubby	*cubby;

    cubby = cubby_init();
    cubby_push(cubby, "first key", "some value");
    ft_printf("value: %s\n", cubby_pull(cubby, "first key"));
    cubby_push(cubby, "first key", "some other value");
    ft_printf("value: %s\n", cubby_pull(cubby, "first key"));
    cubby_remove(cubby, "first key");
    ft_printf("value: %s\n", cubby_pull(cubby, "first key"));
    cubby_close(&cubby);
    return (0);
}
