#include "match.h"

int		no_wild(char *str)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (str[j])
	{
		if (str[j] != '*')
			i++;
		j++;
	}
	return (i);
}

int		match(char *a, char *b)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (no_wild(a) == 0 && ft_strlen(a) != 0)
		return (1);
	while (b[j] || a[i])
	{
		while (a[i] == '*' && a[i])
			i++;
		while (b[j] != a[i] && b[j])
			j++;
		if (a[i] && b[j] && a[i] != b[j] && a[i] != '*')
			return (0);
		else if (a[i] && a[i] == b[j++])
			i++;
		if (i == ft_strlen(a) && a[i] == '*')
			return (1);
		if (a[i] && b[j] == '\0' && a[i] != '*'
			|| a[i] == '\0' && b[j])
			return (0);
	}
	return (a[i] == '\0' && b[j] == '\0' ? 1 : 0);
}

int		main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putchar('\n');
		return (0);
	}
	if (match(argv[1], argv[2]))
		ft_putstr("MATCH ");
	else
		ft_putstr("DON'T MATCH\n");
	return (0);
}
