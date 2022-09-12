#include "libft.h"

static void	lengths(int n, size_t *len, int *weight) {
	if (n >= 0) {
		*len = 0;
		n = -n;
	}
	*weight = 1;
	while (n / *weight < -9)
	{
		*weight *= 10;
		*len += 1;
	}
}

char		*ft_itoa(int n)
{
	int			weight;
	size_t		len = 1;
	lengths(n, &len, &weight);
	char *str = (char *)calloc(sizeof(char), (len + 1));
	if (str == NULL)
		return (NULL);
	size_t cur = 0;
	if (n < 0)
	{
		str[cur] = '-';
		cur++;
	}
	if (n > 0)
		n = -n;
	while (weight >= 1)
	{
		str[cur++] = -(n / weight % 10) + 48;
		weight /= 10;
	}
	return (str);
}
