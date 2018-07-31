
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	if (start > (unsigned int)ft_strlen((char *)s) || s == NULL)
		return (NULL);
	if(!(res = (char *)malloc(sizeof(char)*len + 1)))
		return (NULL);
	i = 0;
	while (s[i] && i < len)
	{
		res[i] = s[start];
		++i;
		++start;
	}
	res[i] = '\0';
	return (res);
}
