/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 04:00:02 by sessarhi          #+#    #+#             */
/*   Updated: 2024/03/11 06:00:44 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0 ;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	return (-42);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	check_sp_nl(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		if (av[i][0] == '\0')
			return (0);
		while (av[i][j])
		{
			while (av[i][j] == ' ')
				j++;
			if (av[i][j] == '\0')
				return (0);
			if (av[i][j] != ' ')
				break ;
		}
		i++;
	}
	return (1);
}

int	get_pos(t_list *stack, int nb)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (nb == stack->index)
			break ;
		stack = stack->next;
		pos++;
	}
	return (pos);
}
