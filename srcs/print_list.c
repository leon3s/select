#include "mys.h"

void	print_list(t_list *list, char flag)
{
	t_list	*tmp;

	tmp = list;
	tputs(tgetstr("cl", NULL), 0, ft_putchar);
	easy_print(tmp);
	(!(tmp->next)) ? 0 : (tmp->len == 0) ? 0 : write(1, "\n", 1);
	tmp = tmp->next;
	while (tmp != list)
	{
		easy_print(tmp);
		(!(tmp->next)) ? 0 : (tmp->len == 0) ? 0 : write(1, "\n", 1);
		tmp = tmp->next;
	}
	if (flag == 1)
		tputs(tgetstr("ho", NULL), 0, ft_putchar);
	tputs(tgetstr("vi", NULL), 0, ft_putchar);
}
