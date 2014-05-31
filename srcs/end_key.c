/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverniss </var/mail/lverniss>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/04 18:46:16 by lverniss          #+#    #+#             */
/*   Updated: 2014/05/04 18:46:20 by lverniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mys.h"

char	end_key(t_core **core, unsigned int key)
{
	if (key == ESC)
	{
		tputs(tgetstr("cl", NULL), 0, ft_putchar);
		return (0);
	}
	if (key == ENTER)
	{
		tputs(tgetstr("cl", NULL), 0, ft_putchar);
		print_ac((*core)->s_list);
		return (0);
	}
	return (1);
}
