#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	size_t len_needle;

	if (!(strcmp(haystack, needle)) || ft_strlen(needle) == 0)
		return ((char *)haystack);
	else if (!ft_strlen(haystack))
		return (NULL);
	len_needle = ft_strlen(needle);
	i = 0;
	while (haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (haystack[i + j] == needle[j] && j < len_needle)
				++j;
			if (j == len_needle)
				return ((char *)haystack + i);
		}
		++i;
	}
	return (NULL);
}
