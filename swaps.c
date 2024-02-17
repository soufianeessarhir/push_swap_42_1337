/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 04:54:38 by sessarhi          #+#    #+#             */
/*   Updated: 2024/02/17 17:46:46 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_list **stack_a)
{
	int tmp;
	int tmp1;
	tmp = (*stack_a)->content;
	tmp1 = (*stack_a)->index;
	
	(*stack_a)->content = (*stack_a)->next->content;
	(*stack_a)->index = (*stack_a)->next->index;
	(*stack_a)->next->content = tmp;
	(*stack_a)->next->index = tmp1;
	write(1,"sa\n",3);
}
void sb(t_list **stack_b)
{
	int tmp;
	int tmp1;
	
	tmp = (*stack_b)->content;
	tmp1 = (*stack_b)->index;
	
	(*stack_b)->content = (*stack_b)->next->content;
	(*stack_b)->index = (*stack_b)->next->index;
	(*stack_b)->next->content = tmp;
	(*stack_b)->next->index = tmp1;
	
	write(1,"sb\n",3);
	
}
void ss(t_list **stack_b,t_list **stack_a)
{
	sa(stack_a);
	sb(stack_b);
}