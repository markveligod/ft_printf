#include "libft.h"

void	*ft_memccpy(void *dest, const void *source, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*src;
	unsigned char	ch;
	size_t			i;

	i = 0;
	d = (unsigned char *)dest;
	src = (unsigned char *)source;
	ch = (unsigned char)c;
	while (i < n)
	{
		d[i] = src[i];
		if (src[i] == ch)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
