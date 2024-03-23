/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:17:46 by sessarhi          #+#    #+#             */
/*   Updated: 2024/03/11 09:06:52 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	helper(t_list **stack_a, t_list **stack_b, char **val, int i)
{
	if (ft_strcmp(val[i], "pa\n") == 0)
		pa(stack_a, stack_b);
	else if (ft_strcmp(val[i], "pb\n") == 0)
		pb(stack_a, stack_b);
	else if (ft_strcmp(val[i], "rra\n") == 0)
		rra(stack_a);
	else if (ft_strcmp(val[i], "rrb\n") == 0)
		rrb(stack_b);
	else if (ft_strcmp(val[i], "rrr\n") == 0)
	{
		rra(stack_a);
		rrb(stack_b);
	}
}

void	actions(t_list	**stack_a, t_list **stack_b, char **val)
{
	int	i;

	i = 0;
	while (val[i])
	{
		if (ft_strcmp(val[i], "sa\n") == 0)
			sa(stack_a);
		else if (ft_strcmp(val[i], "sb\n") == 0)
			sb(stack_b);
		else if (ft_strcmp(val[i], "ra\n") == 0)
			ra(stack_a);
		else if (ft_strcmp(val[i], "rb\n") == 0)
			rb(stack_b);
		else if (ft_strcmp(val[i], "ss\n") == 0)
			ss(stack_a, stack_b);
		else if (ft_strcmp(val[i], "rr\n") == 0)
		{
			ra(stack_a);
			rb(stack_b);
		}
		helper(stack_a, stack_b, val, i);
		i++;
	}
}

int	if_sort(t_list *stack_a)
{
	if (stack_a)
	{
		while (stack_a->next)
		{
			if (stack_a->content > stack_a->next->content)
				return (1);
			stack_a = stack_a->next;
		}
	}
	return (0);
}

void	check_sort_actions(t_list **stack_a, t_list **stack_b)
{
	char	**val;
	int		i;

	i = 0;
	val = malloc(sizeof(char *) * INT32_MAX);
	val[i] = get_next_line(0);
	while (val[i] != NULL)
	{
		if (ft_strcmp(val[i], "sa\n") == 0 || ft_strcmp(val[i], "sb\n") == 0
			|| ft_strcmp(val[i], "ra\n") == 0 || ft_strcmp(val[i], "rb\n") == 0
			|| ft_strcmp(val[i], "ss\n") == 0 || ft_strcmp(val[i], "rr\n") == 0
			|| ft_strcmp(val[i], "pa\n") == 0 || ft_strcmp(val[i], "pb\n") == 0
			|| ft_strcmp(val[i], "rra\n") == 0
			|| ft_strcmp(val[i], "rrb\n") == 0
			|| ft_strcmp(val[i], "rrr\n") == 0)
			i++;
		else
			exit_ations(stack_a, stack_b, val);
		val[i] = get_next_line(0);
	}
	val[i] = NULL;
	actions(stack_a, stack_b, val);
	my_free(val);
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
