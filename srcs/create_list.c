/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverniss </var/mail/lverniss>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/04 18:49:30 by lverniss          #+#    #+#             */
/*   Updated: 2014/05/04 18:49:43 by lverniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mys.h"

char	create_lst(t_list *s_list, char **av)
{
	t_list	*tmp;
	size_t	cn;
	t_list	*s;

	cn = 0;
	s_list->prev = NULL;
	s = s_list;
	while (*(av + ++cn))
	{
		if (!(s_list->entry = (char *)ft_strdup(*(av + cn), &s_list->len)))
			return (0);
		s_list->flag = 0;
		s_list->ul = 0;
		if (*(av + cn + 1))
		{
			if (!(s_list->next = malloc(sizeof(*s_list))))
				return (0);
			tmp = s_list;
			s_list = s_list->next;
			s_list->prev = tmp;
		}
	}
	s_list->next = s;
	s->prev = s_list;
	return (1);
}
