/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverniss </var/mail/lverniss>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/04 18:46:00 by lverniss          #+#    #+#             */
/*   Updated: 2014/05/04 18:46:03 by lverniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mys.h"

void	easy_print(t_list *tmp)
{
	if (tmp->flag)
		tputs(tgetstr("mr", NULL), 0, ft_putchar);
	else
		tputs(tgetstr("me", NULL), 0, ft_putchar);
	if (tmp->ul == 1)
	{
		tputs(tgetstr("sc", NULL), 0, ft_putchar);
		tputs(tgetstr("us", NULL), 0, ft_putchar);
		write(0, tmp->entry, tmp->len);
		tputs(tgetstr("ue", NULL), 0, ft_putchar);
		tputs(tgetstr("rc", NULL), 0, ft_putchar);
	}
	else
	{
		tputs(tgetstr("sc", NULL), 0, ft_putchar);
		write(0, tmp->entry, tmp->len);
		tputs(tgetstr("rc", NULL), 0, ft_putchar);
	}
}
