/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 04:54:00 by sessarhi          #+#    #+#             */
/*   Updated: 2024/02/11 07:11:13 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pa(t_list **stack_a,t_list **stack_b)
{
	int tmp;

	tmp = (*stack_a)->content;
}
int main(int ac, char  **av)
{
	t_list *stack_a;
	 stack_a = NULL;
	if (parcing(ac, av, &stack_a) == 0)
	{
		write(1, "Error\n",6);
		return (0);
	}
	rra(&stack_a);
	while(stack_a)
	{
		printf("%d\n", stack_a->content);
		stack_a = stack_a->next;
	} 
	return 0;
}

