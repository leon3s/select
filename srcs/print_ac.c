/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ac.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverniss </var/mail/lverniss>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/04 18:53:49 by lverniss          #+#    #+#             */
/*   Updated: 2014/05/04 18:53:53 by lverniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mys.h"

void	print_ac(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	if (tmp->flag == 1)
	{
		write(1, tmp->entry, tmp->len);
		write(1, "\n", 1);
	}
	tmp = tmp->next;
	while (tmp != lst)
	{
		if (tmp->flag == 1)
		{
			write(1, tmp->entry, tmp->len);
			write(1, "\n", 1);
		}
		tmp = tmp->next;
	}
}
