/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 04:00:02 by sessarhi          #+#    #+#             */
/*   Updated: 2024/02/21 11:10:15 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
int get_pos(t_list *stack,int nb)
{
	int i;
	
	i = 1;
	while(stack)
	{
		if (nb == stack->index)
			break;
		i++;
		stack = stack->next;	
	}
	return i;
}