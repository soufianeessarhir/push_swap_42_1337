/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_mov1_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 05:41:30 by sessarhi          #+#    #+#             */
/*   Updated: 2024/03/11 05:55:16 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ra(t_list	**stack_a)
{
	int		tmp;
	int		tmp1;
	t_list	*ptr;

	if ((ft_lstsize(*stack_a) < 2))
		return ;
	ptr = (*stack_a);
	tmp = (*stack_a)->content;
	tmp1 = (*stack_a)->index;
	(*stack_a) = (*stack_a)->next;
	free(ptr);
	ptr = NULL;
	ft_lstadd_back(stack_a, ft_lstnew(tmp, tmp1));
}

void	rb(t_list	**stack_b)
{
	int		tmp;
	int		tmp1;
	t_list	*ptr;

	if (!(ft_lstsize(*stack_b) > 1))
		return ;
	tmp = (*stack_b)->content;
	tmp1 = (*stack_b)->index;
	ptr = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	free (ptr);
	ptr = NULL;
	ft_lstadd_back(stack_b, ft_lstnew(tmp, tmp1));
}

void	rr(t_list	**stack_a, t_list	**stack_b)
{
	if (!(ft_lstsize(*stack_b) > 1) || !(ft_lstsize(*stack_a) > 1))
		return ;
	ra (stack_a);
	rb (stack_b);
}
