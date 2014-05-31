#ifndef MYS_H
# define MYS_H

# include "libc.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <curses.h>
# include <term.h>
# include <termios.h>
//# include <stropts.h>
# include <signal.h>

# define KEYLEFT	4479771
# define KEYRIGHT	4414235
# define KEYUP		4283163
# define KEYDOWN	4348699
# define SPACE		32
# define DEL		127 
# define ESC		27
# define ENTER		10

typedef struct	s_list t_list;
typedef struct	s_core	t_core;

struct		s_list
{
	void	*entry;
	size_t	len;
	int	flag;
	int	ul;
	t_list	*next;
	t_list	*prev;
};

struct		s_core
{
	t_list		*s_list;
	char		*name;
	int		resize;
	int		dev;
	int		ac;
	struct termios	save;
};

char	ft_raw_mod(void);
char	create_lst(t_list *s_list, char **av);
void	easy_print(t_list *tmp);
void	print_list(t_list *list, char flag);
void	keydown(t_list **tmp);
void	keyup(t_list **tmp);
void	keyspace(t_list **tmp, t_core *core);
char	del_key(t_core **core, t_list **tmp, unsigned int key);
void	move_keys(t_core **core, t_list **tmp, unsigned int key);
char	end_key(t_core **core, unsigned int key);
char	read_entry(t_core *core);
void	print_ac(t_list *lst);
char	init_core(t_core *core, char **av);
void	free_fast(t_list **f);
#endif
