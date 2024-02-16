/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_any.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 08:32:03 by sessarhi          #+#    #+#             */
/*   Updated: 2024/02/16 08:32:44 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int _min(t_list *stack_a)
{
	int min;
	t_list *tmp;
	
	min = stack_a->content;
	tmp = stack_a;
	while (tmp->next)
	{
		if (min > tmp->next->content)
			min = tmp->next->content;
		tmp = tmp->next;
	}
	return min;
}
int get_pos(t_list *stack,int  min)
{
	t_list *tmp;
	int i;
	
	tmp = (stack);
	i = 1;
	while(tmp->next)
	{
		if (min == tmp->content)
			return (i);
		tmp = tmp->next;
		i++;	
	}
	return 0;
}
void sort_all(t_list **stack_a, t_list **stack_b)
{
	int min;

	while ((*stack_a))
	{
		min = _min(*stack_a);
		if (get_pos((*stack_a),min) >= (ft_lstsize(*stack_a) / 2))
		{
			while ((*stack_a)->content != min)
				rra(stack_a);
			pb(stack_a,stack_b);
		}
		else if (get_pos((*stack_a),min) < (ft_lstsize(*stack_a) / 2))
		{
			while ((*stack_a)->content != min)
				ra(stack_a);
			pb(stack_a,stack_b);
		}
	}
	while ((*stack_b))
		pa(stack_a,stack_b);
}