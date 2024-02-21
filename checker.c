/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:17:46 by sessarhi          #+#    #+#             */
/*   Updated: 2024/02/21 18:57:43 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void check_sort_actions(t_list **stack_a,t_list **stack_b)
{
	while (get_next_line(0))
	{
		
	}
	
}
int main(int ac, char **av)
{
	t_list *stack_a;
	t_list *stack_b;
	stack_a = NULL;
	stack_b = NULL;
	
	if (parcing(ac, av, &stack_a) == 0)
	{
		write(1, "Error\n",6);
		return (0);
	}
	else
		check_sort_actions(&stack_a,&stack_b);
	return 0;
}