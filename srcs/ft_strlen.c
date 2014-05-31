/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverniss </var/mail/lverniss>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/04 18:46:53 by lverniss          #+#    #+#             */
/*   Updated: 2014/05/04 18:46:58 by lverniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libc.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = -1;
	while (*(str + ++count))
		;
	return (count);
}
