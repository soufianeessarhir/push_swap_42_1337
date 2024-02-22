/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:17:46 by sessarhi          #+#    #+#             */
/*   Updated: 2024/02/22 12:43:24 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void actions(t_list  **stack_a,t_list **stack_b, char *val)
{
	
	if (ft_strcmp(val,"ra") == 0)
		ra(stack_a);
	else if (ft_strcmp(val,"rb") == 0)
		rb(stack_b);
	else if (ft_strcmp(val,"rr") == 0)
	{
		ra(stack_a);
		rb(stack_b);
	}
	else if (ft_strcmp(val,"pa") == 0)
		pa(stack_a,stack_b);
	else if (ft_strcmp(val,"pb") == 0)
		pb(stack_a,stack_b);
	else if (ft_strcmp(val,"rra") == 0)
		rra(stack_a);
	else if (ft_strcmp(val,"rrb") == 0)
		rrb(stack_b);
	else if (ft_strcmp(val,"rrr") == 0)
	{
		rra(stack_a);
		rrb(stack_b);
	}
}
int if_sort(t_list *stack_a)
{
	while (stack_a->next)
	{
		if (stack_a->content > stack_a->next->content)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}
void check_sort_actions(t_list **stack_a, t_list **stack_b)
{
	char *val;

	while ((val = get_next_line(0)) !=NULL)
	{
		if (ft_strcmp(val, "sa") == 0)
			sa(stack_a);
		else if (ft_strcmp(val, "sb") == 0)
			sb(stack_b);
		else
			actions(stack_a, stack_b, val);

		free(val);
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
	if (if_sort(stack_a))
		write(1,"ko\n", 3);
	else
		write(1,"ok\n", 3);
	return 0;
}