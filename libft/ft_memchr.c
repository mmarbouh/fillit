
#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	ch;
	size_t			i;

	i = 0;
	p = (unsigned char *)s;
	ch = c;
	while (i < n)
	{
		if (*p == ch)
			return (p);
		++p;
		++i;
	}
	return (NULL);
}
