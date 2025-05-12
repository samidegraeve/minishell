
#include "../inc/libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;

	str = s;
	while (n && *str)
	{
		*str = '\0';
		n--;
		str++;
	}
}
