/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 04:54:00 by sessarhi          #+#    #+#             */
/*   Updated: 2024/02/16 12:20:48 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int _min_(t_list **stack_a)
{
	int min;
	int i;
	t_list *tmp;
	
	tmp = (*stack_a);
	i = 0;
	while ((*stack_a)->next)
	{
		printf("%d-------------------%d\n",(*stack_a)->content,(*stack_a)->next->content);
		if ((*stack_a)->next->content < (*stack_a)->content)
		{
			printf("%d-------------------\n",min);
			if ((*stack_a)->next->index == -1)
				min = (*stack_a)->next->content;
		}
		(*stack_a) = (*stack_a)->next;
		i++;
	}
	
	exit(1);
	(*stack_a) = tmp;
	return min;
}
void indexing(t_list **stack_a)
{
	int i;
	int min;
	t_list *tmp;
	
	i = 0;
	tmp = (*stack_a);
	min = _min_(stack_a);
	
	while (i < ft_lstsize(*stack_a))
	{
		while ((*stack_a)->next)
		{
			if ((*stack_a)->content == min)
				(*stack_a)->index = i;
			(*stack_a) = (*stack_a)->next;	
		}
		i++;
		(*stack_a) = tmp;
		min = _min_(stack_a);
	}
	
	// while ((*stack_a)->next)
	// {
	// 	printf("%d\n", (*stack_a)->index);
	// 	(*stack_a) = (*stack_a)->next;
	// }
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
	if (ft_lstsize(stack_a) == 5 || ft_lstsize(stack_a) == 4)
		sort5(&stack_a,&stack_b);
	else
	sort_all(&stack_a,&stack_b);
	// if (ft_lstsize(stack_a) == 2)
	// {
	// 	if (stack_a->content > stack_a->next->content)
	// 		sa (&stack_a);
	// }
	// if (ft_lstsize(stack_a) == 3)
	// 	sort3(&stack_a);
	while(stack_a)
	{
		printf("%d\n", stack_a->index);
		stack_a = stack_a->next;
	} 
	// while(stack_b)
	// {
	// 	printf("%d\n", stack_b->content);
	// 	stack_b = stack_b->next;
	// } 
	return 0;
}
