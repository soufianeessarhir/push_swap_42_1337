/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 21:16:15 by sessarhi          #+#    #+#             */
/*   Updated: 2024/03/11 08:50:44 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	free_stack(t_list **stack)
{
	t_list	*tmp;

	while ((*stack))
	{
		tmp = (*stack)->next;
		free((*stack));
		(*stack) = tmp;
	}
	(*stack) = NULL;
}

void	exit_ations(t_list **stack_a, t_list **stack_b, char **val)
{
	my_free(val);
	free_stack(stack_a);
	free_stack(stack_b);
	write(1, "Error\n", 6);
	exit(1);
}
