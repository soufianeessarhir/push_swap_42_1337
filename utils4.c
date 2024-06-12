/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 21:16:15 by sessarhi          #+#    #+#             */
/*   Updated: 2024/03/11 06:08:12 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
