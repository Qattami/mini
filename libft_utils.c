#include "mini.h"

char	*strdupl(const char *s, int i)
{
	char	*p;
	int j;

	j = 0;
	p = malloc(sizeof(char) * (i + 1));
	if (p == NULL)
		return (NULL);
	while (j < i)
	{
		p[j] = s[j];
		j++;
	}
	p[j] = 0;
	return (p);
}
char	*strdupl2(char *s, char c)
{
	char	*p;
	int j;
	int i;

	j = 0;
	i = ft_strlen(s);
	while(i > 0 && s[i] != c)
		i--;
	p = malloc(sizeof(char) * (i + 1));
	if (p == NULL)
		return (NULL);
	while (s[j] && s[j] != c)
		j++;
	j++;
		i = 0;
	while(s[j])
	{
		p[i] = s[j];
		i++;
		j++;
	}
	p[i] = 0;
	return (p);
}
char	*ft_strrchr(const char *str, int character)
{
	int	i;

	i = ft_strlen((char *)str);
	while (i >= 0)
	{
		if (str[i] == (char)character)
			return ((char *)str + i);
		i--;
	}
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	i = 0;
	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (a[i] && b[i] && n - 1 > i && a[i] == b[i])
		i++;
	return (a[i] - b[i]);
}
int ft_strlen(char *s)
{
	int i;

	i = 0;
	while(s[i])
		i++;
	return i;
}

