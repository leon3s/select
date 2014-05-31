/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverniss </var/mail/lverniss>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/04 18:46:42 by lverniss          #+#    #+#             */
/*   Updated: 2014/05/04 18:46:46 by lverniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libc.h"

char	*ft_strdup(const char *str, size_t *size)
{
	char	*ret;
	size_t	count;

	if (!(*size))
		*size = ft_strlen(str);
	if (!(ret = malloc(sizeof(*ret) * ((*size + 1)))))
		return (NULL);
	count = -1;
	while (*(str + ++count))
		*(ret + count) = *(str + count);
	*(ret + count) = 0;
	return (ret);
}
