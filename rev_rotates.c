/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 06:00:17 by sessarhi          #+#    #+#             */
/*   Updated: 2024/02/23 19:16:59 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **stack_a)
{
	int		tmp;
	int		tmp1;
	t_list	*head;
	t_list	*prev;

	head = (*stack_a);
	while ((*stack_a)->next)
	{
		prev = (*stack_a);
		(*stack_a) = (*stack_a)->next;
	}
	tmp = (*stack_a)->content;
	tmp1 = (*stack_a)->index;
	ft_lstadd_front(&head, ft_lstnew(tmp, tmp1));
	free((*stack_a));
	prev->next = NULL;
	(*stack_a) = head;
	write(1, "rra\n", 4);
}

void	rrb(t_list **stack_b)
{
	int		tmp;
	int		tmp1;
	t_list	*head;
	t_list	*prev;

	head = (*stack_b);
	while ((*stack_b)->next)
	{
		prev = (*stack_b);
		(*stack_b) = (*stack_b)->next;
	}
	tmp = (*stack_b)->content;
	tmp1 = (*stack_b)->index;
	free((*stack_b));
	prev->next = NULL;
	ft_lstadd_front(&head, ft_lstnew(tmp, tmp1));
	(*stack_b) = head;
	write(1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
