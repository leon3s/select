/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverniss </var/mail/lverniss>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/04 18:47:15 by lverniss          #+#    #+#             */
/*   Updated: 2014/05/04 18:52:12 by lverniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mys.h"

char		init_core(t_core *core, char **av)
{
	size_t	size;

	size = 8;
	if (!(core->s_list = malloc(sizeof(*core->s_list))))
		return (0);
	if (!(create_lst(core->s_list, av)))
		return (0);
	if ((core->dev = ttyslot()) == -1)
		return (0);
	if (!(core->name = ft_strdup("/dev/tty", &size)))
		return (0);
	close(0);
	if ((core->dev = open(core->name, O_RDWR)) < 0)
		return (0);
	if ((tcgetattr(0, &core->save)) == -1)
		return (0);
	if (!(ft_raw_mod()))
		return (0);
	return (1);
}
