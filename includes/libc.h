#ifndef LIBC_H
# define LIBC_H

# include <unistd.h>
# include <stdlib.h>


char	*ft_strdup(const char *str, size_t *size);
void	ft_bzero(void *ptr, size_t len);
size_t	ft_strlen(const char *str);
int	ft_putchar(int c);

#endif
