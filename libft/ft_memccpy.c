
#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*desti;
	unsigned char	*sourc;
	size_t	i;

	desti =  (unsigned char*)dest;
	sourc = (unsigned char*)src;
	i = 0;
	while (i < n && sourc[i])
	{
		*(desti + i) = *(sourc + i);
		if (sourc[i] == (unsigned char)c)
			return (dest + i + 1);
		++i;
	}
	return (NULL);
}
