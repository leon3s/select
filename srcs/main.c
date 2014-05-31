/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverniss </var/mail/lverniss>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/04 18:53:23 by lverniss          #+#    #+#             */
/*   Updated: 2014/05/04 18:54:20 by lverniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mys.h"

int		ft_putchar(int c)
{
	return (write(2, &c, 1));
}

void	free_fast(t_list **tmp)
{
	free((*tmp)->entry);
	(*tmp)->len = 0;
	(*tmp)->entry = NULL;
	free((*tmp));
	(*tmp) = NULL;
}

int		main(int ac, char **av)
{
	t_core	core;

	ft_bzero(&core, sizeof(core));
	if (ac == 1)
		return (0);
	if (!(init_core(&core, av)))
		return (0);
	read_entry(&core);
	tputs(tgetstr("ve", NULL), 0, ft_putchar);
	if ((tcsetattr(0, TCSANOW, &core.save)) == -1)
		return (0);
	return (0);
}
