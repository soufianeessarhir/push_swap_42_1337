/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_mov.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 04:54:38 by sessarhi          #+#    #+#             */
/*   Updated: 2024/02/22 12:05:07 by sessarhi         ###   ########.fr       */
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
	

	
}
void ss(t_list **stack_b,t_list **stack_a)
{
	sa(stack_a);
	sb(stack_b);
}
void pb(t_list **stack_a,t_list **stack_b)
{
	int tmp;
	int tmp1;
	t_list *ptr;

	tmp = (*stack_a)->content;
	tmp1 = (*stack_a)->index;
	ptr = (*stack_a);
	*stack_a = (*stack_a)->next;
	free(ptr);
	ptr = NULL;
	ft_lstadd_front(stack_b,ft_lstnew(tmp,tmp1));

}
void pa(t_list **stack_a,t_list **stack_b)
{
	int tmp;
	int tmp1;
	t_list *ptr;

	tmp = (*stack_b)->content;
	tmp1 = (*stack_b)->index;
	ptr = (*stack_b);
	*stack_b = (*stack_b)->next;
	free(ptr);
	ptr = NULL;
	ft_lstadd_front(stack_a,ft_lstnew(tmp,tmp1));
	
}