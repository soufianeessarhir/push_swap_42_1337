/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 04:54:38 by sessarhi          #+#    #+#             */
/*   Updated: 2024/02/11 05:55:57 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_list **stack_a)
{
	int tmp;
	tmp = (*stack_a)->content;
	
	(*stack_a)->content = (*stack_a)->next->content;
	(*stack_a)->next->content = tmp;
	write(1,"sa\n",3);
}
void sb(t_list **stack_b)
{
	int tmp;
	tmp = (*stack_b)->content;
	
	(*stack_b)->content = (*stack_b)->next->content;
	(*stack_b)->next->content = tmp;
	write(1,"sb\n",3);
	
}
void ss(t_list **stack_b,t_list **stack_a)
{
	sa(stack_a);
	sb(stack_b);
}