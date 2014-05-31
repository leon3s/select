/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_entry.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverniss </var/mail/lverniss>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/04 18:50:01 by lverniss          #+#    #+#             */
/*   Updated: 2014/05/04 18:56:14 by lverniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mys.h"

char				read_entry(t_core *core)
{
	unsigned int	key;
	t_list			*tmp;
	int				ret;

	tmp = core->s_list;
	tmp->ul = 1;
	print_list(core->s_list, 1);
	ft_bzero(&key, sizeof(key));
	while ((ret = read(core->dev, &key, 4)) != -1)
	{
		move_keys(&core, &tmp, key);
		if (!(del_key(&core, &tmp, key)))
			return (0);
		if (!(end_key(&core, key)))
			return (0);
		ft_bzero(&key, sizeof(key));
	}
	if (ret == -1)
		return (0);
	return (1);
}
