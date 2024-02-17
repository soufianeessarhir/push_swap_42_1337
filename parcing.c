/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 04:54:24 by sessarhi          #+#    #+#             */
/*   Updated: 2024/02/17 17:33:12 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
int check_dig(char **av)
{
	int i ;
	int j ;

	i = 0;
	while(av[i])
	{
			j = 0;
		while(av[i][j])
		{
			if (ft_isdigit(av[i][j]) == 0 && av[i][0] != '-' && av[i][0] != '+')
				return(0);
			j++;
		}
		i++;
	}
	return (1);
}

// int is_space(int c)
// {

// }
int check_sp_nl(int ac,char **av)
{
	int i ;
	int j ;

	i = 1;
	while(i < ac)
	{
		j = 0;
		if (av[i][0] == '\0')
			return (0);
		while(av[i][j])
		{
			while (av[i][j] == ' ')
				j++;
			if (av[i][j] == '\0')
				return(0);
			if (av[i][j] != ' ')
				break;
		}
		i++;
	}
	return (1);
}
int check_dup(char **av)
{
	int i;
	int j;

	i = 0;

	while (av[i])
	{
		j = i + 1;
		while (av[j])
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
int parcing(int ac, char **av, t_list **stack_a)
{
	
	int i;

	i = 0;
	if (check_sp_nl(ac,av) == 0)
		return (0);
	av = splitargs(ac,av);
	i = 0;
	while (av[i])
	{
		if (ft_sing_range(av[i]) == 0)
			return (0);
		i++;
	}
	if (check_dup(av) == 0 || check_dig(av) == 0)
		return 0;
	i = 0;
	while (av[i])
	{
		ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(av[i]),-1));
		i++;
	}
	
	
	return 1;
}
