#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{

	size_t	i;
	size_t	j;
	size_t	len_little;

	if (!(strcmp(big, little)) || ft_strlen(little) == 0)
		return ((char *)big);
	else if (!ft_strlen(big))
		return (NULL);
	len_little = ft_strlen(little);
	i = 0;
	while (i < len && big[i])
	{
		if (big[i] == little[0])
		{
			j = 0;
			while ((i+j) < len && big[i + j] == little[j] && j < len_little)
				++j;
			if (j == len_little)
				return ((char *)big + i);
		}
		++i;
	}
	return (NULL);
}
