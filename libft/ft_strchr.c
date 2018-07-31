#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = -1;
	while(++i <= ft_strlen(s))
		if (s[i] == c)
			return ((char *)s + i);
	return (NULL);
}
