/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 04:54:00 by sessarhi          #+#    #+#             */
/*   Updated: 2024/02/17 17:34:22 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void sort_100(t_list **stack_a, t_list **stack_b)
// {
// 	indexing(&stack_a);
// }
int main(int ac, char  **av)
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
	indexing(&stack_a);
	if (ft_lstsize(stack_a) == 5 || ft_lstsize(stack_a) == 4)
		sort5(&stack_a,&stack_b);
	else
	sort_all(&stack_a,&stack_b);
	while(stack_a)
	{
		printf("%d ===> index = %d\n" , stack_a->content, stack_a->index);
		stack_a = stack_a->next;
	} 
	// if (ft_lstsize(stack_a) == 2)
	// {
	// 	if (stack_a->content > stack_a->next->content)
	// 		sa (&stack_a);
	// }
	// if (ft_lstsize(stack_a) == 3)
	// 	sort3(&stack_a);
	// while(stack_b)
	// {
	// 	printf("%d\n", stack_b->content);
	// 	stack_b = stack_b->next;
	// } 
	return 0;
}
