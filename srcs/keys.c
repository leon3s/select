/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverniss </var/mail/lverniss>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/04 18:48:58 by lverniss          #+#    #+#             */
/*   Updated: 2014/05/04 18:53:12 by lverniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mys.h"

void	keydown(t_list **tmp)
{
	(*tmp)->ul = 0;
	((*tmp)) = ((*tmp)->next);
	(*tmp)->ul = 1;
}

void	keyup(t_list **tmp)
{
	(*tmp)->ul = 0;
	((*tmp)) = ((*tmp)->prev);
	(*tmp)->ul = 1;
}

void	keyspace(t_list **tmp, t_core *core)
{
	if (!((*tmp)->flag))
		((*tmp)->flag) = 1;
	else
		(*tmp)->flag = 0;
	if (!((*tmp)->next))
		(*tmp) = core->s_list;
	else
		keydown(tmp);
}

void	move_keys(t_core **core, t_list **tmp, unsigned int key)
{
	if (key == KEYDOWN && (*tmp)->next)
	{
		keydown(&(*tmp));
		print_list((*core)->s_list, 1);
	}
	else if (key == KEYUP)
	{
		keyup(&(*tmp));
		print_list((*core)->s_list, 1);
	}
	if (key == SPACE)
	{
		keyspace(&(*tmp), *core);
		print_list((*core)->s_list, 1);
	}
}

char	del_key(t_core **core, t_list **tmp, unsigned int key)
{
	t_list	*fr;

	if (key == DEL)
	{
		if (*tmp == (*core)->s_list)
			(*core)->s_list = (*tmp)->next;
		if ((*tmp) != (*tmp)->next)
		{
			fr = *tmp;
			(*tmp)->next->prev = (*tmp)->prev;
			(*tmp)->prev->next = (*tmp)->next;
			keydown(&(*tmp));
			free_fast(&fr);
		}
		else
			return (0);
		print_list((*core)->s_list, 1);
	}
	return (1);
}
