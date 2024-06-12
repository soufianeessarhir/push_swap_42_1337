/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 04:54:00 by sessarhi          #+#    #+#             */
/*   Updated: 2024/02/28 20:12:50 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	if_sort(t_list *stack_a)
{
	while (stack_a->next)
	{
		if (stack_a->content > stack_a->next->content)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

void	which_sort(t_list **stack_a, t_list	**stack_b)
{
	if (ft_lstsize(*stack_a) == 2)
		sa (stack_a);
	else if (ft_lstsize(*stack_a) == 3)
		sort3(stack_a);
	else if (ft_lstsize(*stack_a) == 5 || ft_lstsize(*stack_a) == 4)
		sort5(stack_a, stack_b);
	else
		sort_any(stack_a, stack_b);
}

int	main(int ac, char	**av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac != 1)
	{
		if (parcing(ac, av, &stack_a) == 0)
		{
			write(1, "Error\n", 6);
			free_stack(&stack_a);
			return (0);
		}
		indexing(&stack_a);
		if (if_sort(stack_a))
		{
			which_sort(&stack_a, &stack_b);
		}
		free_stack(&stack_b);
		free_stack(&stack_a);
	}
	return (0);
}
