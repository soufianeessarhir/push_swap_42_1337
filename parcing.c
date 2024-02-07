#include "push_swap.h"
char	**splitargs(int ac, char **av)
{
	int i;
	char *str;

	i = 1;
	str = ft_strdup("");
	while (i < ac)
	{
		str = ft_strjoin(str,av[i]);
		str = ft_strjoin(str," ");
		i++;
	}
return (ft_split(str,' '));
}
int check_dig(int ac,char **av)
{
	int i ;
	int j ;

	i = 1;
	while(i < ac)
	{
			j = 0;
		while(av[i][j])
		{
			if (ft_isdigit(av[i][j]) == 0)
				return(0);
			j++;
		}
		i++;
	}
	return (1);
}
int check_dup(int ac,char **av)
{
	int i;
	int j;

	i = 1;

	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
			{
				return 0;
			}
			j++;
		}
		i++;
	}
	return 1;
}