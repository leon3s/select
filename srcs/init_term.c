/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverniss </var/mail/lverniss>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/04 18:47:35 by lverniss          #+#    #+#             */
/*   Updated: 2014/05/04 18:52:52 by lverniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mys.h"

char				ft_raw_mod(void)
{
	struct termios	terms;
	char			*term;
	size_t			size;

	size = 0;
	if (!(term = getenv("TERM")))
		term = ft_strdup("linux", &size);
	if (!(tgetent(NULL, term)))
		return (0);
	if ((tcgetattr(0, &terms)) == -1)
		return (0);
	terms.c_lflag &= ~ICANON;
	terms.c_lflag &= ~ECHO;
	terms.c_lflag |= ISIG;
	if ((cfgetispeed(&terms)) == (unsigned)-1)
		return (0);
	if ((cfsetispeed(&terms, 0)) == -1)
		return (0);
	terms.c_cc[VMIN] = 1;
	if ((tcsetattr(0, TCSANOW, &terms)) == -1)
		return (0);
	return (1);
}
