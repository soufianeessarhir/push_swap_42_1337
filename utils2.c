/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 04:55:13 by sessarhi          #+#    #+#             */
/*   Updated: 2024/02/23 19:12:44 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*newstr;

	i = 0;
	j = 0;
	newstr = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!newstr)
		return (NULL);
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		newstr[i + j] = s2[j];
		j++;
	}
	newstr[i + j] = '\0';
	free((void *)s1);
	s1 = NULL;
	return (newstr);
}

t_list	*ft_lstnew(int content, int index)
{
	t_list	*head;

	head = malloc(sizeof(t_list));
	if (!head)
		return (NULL);
	head->content = content;
	head->index = index;
	head->next = NULL;
	return (head);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!*lst && new)
	{
		(*lst) = new;
		return ;
	}
	if (!new || !*lst)
		return ;
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

int	ft_sing_range(const char *str)
{
	long long	nb;
	int			s;

	nb = 0;
	s = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			s = -1;
		str++;
	}
	if (!(*str >= '0' && *str <= '9'))
		return (0);
	while (*str && (*str >= '0' && *str <= '9'))
	{
		nb = nb * 10 + (*str - '0');
		str++;
		if ((s * nb) > 2147483647 || (s * nb) < -2147483648)
			return (0);
	}
	if (!(*str >= '0' && *str <= '9') && *str != '\0')
		return (0);
	return (1);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}
