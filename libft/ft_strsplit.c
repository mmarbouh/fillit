
#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;
	int		k;
	int		l;

	if(!(res = (char **)malloc(sizeof(char *)*strlen(s))))
		return (NULL);
	k = 0;
	i = 0;
	while (i < (int)strlen(s))
	{
		if (!(res[k] = (char*)malloc(sizeof(char)*26)))
			return (NULL);
		l = 0;
		while (s[i] != c)
		{
			res[k][l] = s[i];
			++l;
			++i;
		}
		res[k][l] = '\0';
		if (l > 0)
			++k;
		++i;
	}
	res[k] = (char*)0;
	return (res);
}
