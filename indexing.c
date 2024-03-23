/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:09:50 by sessarhi          #+#    #+#             */
/*   Updated: 2024/02/23 21:34:51 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	_min_(t_list *stack_a)
{
	int		min;
	t_list	*tmp;

	tmp = stack_a;
	while (tmp)
	{
		if (tmp->index == -1)
		{
			min = tmp->content;
			break ;
		}
		tmp = tmp->next;
	}
	tmp = stack_a;
	while (tmp)
	{
		if (min > tmp->content && tmp->index == -1)
			min = tmp->content;
		tmp = tmp->next;
	}
	return (min);
}

void	indexing(t_list **stack_a)
{
	int		i;
	int		min;
	t_list	*tmp;


	i = 1;
	tmp = (*stack_a);
	(*stack_a) = tmp;
	while (i <= ft_lstsize(*stack_a))
	{
		min = _min_(*stack_a);
		while ((*stack_a))
		{
			if (min == (*stack_a)->content)
				(*stack_a)->index = i;
			(*stack_a) = (*stack_a)->next;
		}
		(*stack_a) = tmp;
		i++;
	}
}

int	get_min_mov(t_list *stack, int max)
{
	t_list	*tmp;
	int		i;

	tmp = stack;
	i = 0;
	while (tmp)
	{
		if (max != tmp->index)
			i++;
		else
			break ;
		tmp = tmp->next;
	}
	if (i <= (ft_lstsize(stack) / 2))
		return (i);
	return (ft_lstsize((stack)) - i);
}
