/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 04:54:00 by sessarhi          #+#    #+#             */
/*   Updated: 2024/02/18 12:35:46 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_100(t_list **stack_a, t_list **stack_b)
{
	int i;
	int r_min;

	i = 0;
	r_min = 0;
	
	while (*stack_a)
	{
		if ((*stack_a)->index >= r_min && (*stack_a)->index < r_min + 20)
		{
			pb(stack_a,stack_b);
			i++;
			if (i >=2 && (*stack_b)->index > (*stack_b)->next->index)
				rb(stack_b);
		}
		else 
			ra(stack_a);
		if (i == 20)
		{
			i = 0;
			r_min = r_min + 20;
		}
		
	}
	while(*stack_b)
	{
		printf("%d ===> index = %d\n" , (*stack_b)->content, (*stack_b)->index);
		(*stack_b) = (*stack_b)->next;
	} 
	exit(1);
}
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
	sort_100(&stack_a,&stack_b);
	// if (ft_lstsize(stack_a) == 5 || ft_lstsize(stack_a) == 4)
	// 	sort5(&stack_a,&stack_b);
	// else
	// sort_all(&stack_a,&stack_b);
	// while(stack_a)
	// {
	// 	printf("%d ===> index = %d\n" , stack_a->content, stack_a->index);
	// 	stack_a = stack_a->next;
	// } 
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
