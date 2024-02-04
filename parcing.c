#include "push_swap.h"

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