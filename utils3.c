/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 04:00:02 by sessarhi          #+#    #+#             */
/*   Updated: 2024/02/20 21:52:42 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
int get_pos(t_list *stack,int nb)
{
	t_list *tmp;
	int i;


	tmp = stack;
	i = 0;
	while(tmp)
	{
		if (nb != tmp->index)
			i++;
		else
			break;
		tmp = tmp->next;	
	}
	return i;
}