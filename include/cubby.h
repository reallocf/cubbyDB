#ifndef CUBBY_H
# define CUBBY_H

# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include "libft.h"

# define SLOT_COUNT 4096

typedef struct		s_elem
{
    char		*key;
    char		*val;
    struct s_elem	*next;
}			t_elem;

typedef struct		s_cubby
{
    int			fd;
    t_elem		**slot;
}			t_cubby;

/* User Interface */
t_cubby			*cubby_init(void);
int			cubby_push(t_cubby *cubby, char *key, char *val);
char			*cubby_pull(t_cubby *cubby, char *key);
int			cubby_remove(t_cubby *cubby, char *key);
void			cubby_close(t_cubby **cubby);

/* For the Program */
unsigned int		hash(char *key);
int			cubby_pusher(t_cubby *cubby, char *key, char *val, int persist);
int			cubby_remover(t_cubby *cubby, char *key, int persist);
void			delete_slot(t_elem **slot);

#endif
