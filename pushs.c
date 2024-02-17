/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 00:59:36 by sessarhi          #+#    #+#             */
/*   Updated: 2024/02/17 17:31:44 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	write(1, "pb\n",3);
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
	write(1, "pa\n",3);
	
}