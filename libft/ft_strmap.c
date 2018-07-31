
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*res;
	size_t	len;

	if (!s || !f)
		return (NULL);
	len = 0;
	while (s[len])
		++len;
	if(!(res = (char *)malloc(sizeof(char) * (len+1))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = (*f)(s[i]);
		++i;
	}
	res[i] = '\0';
	return (res);
}
