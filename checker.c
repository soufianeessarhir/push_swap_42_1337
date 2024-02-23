/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:17:46 by sessarhi          #+#    #+#             */
/*   Updated: 2024/02/23 18:12:06 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	actions(t_list	**stack_a, t_list **stack_b, char *val)
{
	if (ft_strcmp(val, "rr\n") == 0)
	{
		ra(stack_a);
		rb(stack_b);
	}
	else if (ft_strcmp(val, "pa\n") == 0)
		pa(stack_a, stack_b);
	else if (ft_strcmp(val, "pb\n") == 0)
		pb(stack_a, stack_b);
	else if (ft_strcmp(val, "rra\n") == 0)
		rra(stack_a);
	else if (ft_strcmp(val, "rrb\n") == 0)
		rrb(stack_b);
	else if (ft_strcmp(val, "rrr\n") == 0)
	{
		rra(stack_a);
		rrb(stack_b);
	}
	else
	{
		free_stack(stack_a);
		free_stack(stack_b);
		write(1, "Error\n", 6);
		exit(1);
	}
}

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

void	check_sort_actions(t_list **stack_a, t_list **stack_b)
{
	char	*val;

	val = get_next_line(0);
	while (val != NULL)
	{
		if (ft_strcmp(val, "sa\n") == 0)
			sa(stack_a);
		else if (ft_strcmp(val, "sb\n") == 0)
			sb(stack_b);
		else if (ft_strcmp(val, "ra\n") == 0)
			ra(stack_a);
		else if (ft_strcmp(val, "rb\n") == 0)
			rb(stack_b);
		else if (ft_strcmp(val, "ss\n") == 0)
			ss(stack_a, stack_b);
		else
			actions(stack_a, stack_b, val);
		free(val);
		val = get_next_line(0);
	}
}

static	void	free_stack(t_list **stack)
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

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (parcing(ac, av, &stack_a) == 0)
	{
		free_stack(&stack_a);
		write(1, "Error\n", 6);
		return (0);
	}
	if (!(stack_a))
		return (0);
	else
		check_sort_actions(&stack_a, &stack_b);
	if (if_sort(stack_a) || ft_lstsize(stack_b) != 0)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
