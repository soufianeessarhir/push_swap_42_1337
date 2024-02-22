/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:17:46 by sessarhi          #+#    #+#             */
/*   Updated: 2024/02/22 14:53:19 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void actions(t_list  **stack_a,t_list **stack_b, char *val)
{
	
	if (ft_strcmp(val,"ra\n") == 0 && (ft_lstsize(*stack_a) >  1))
		ra(stack_a);
	else if (ft_strcmp(val,"rb\n") == 0 && (ft_lstsize(*stack_b) >  1))
		rb(stack_b);
	else if (ft_strcmp(val,"rr\n") == 0 && (ft_lstsize(*stack_b) >  1 )&&( ft_lstsize(*stack_a) >  1))
	{
		ra(stack_a);
		rb(stack_b);
	}
	else if (ft_strcmp(val,"pa\n") == 0  && (ft_lstsize(*stack_b)))
		pa(stack_a,stack_b);
	else if (ft_strcmp(val,"pb\n") == 0  && (ft_lstsize(*stack_a)))
		pb(stack_a,stack_b);
	else if (ft_strcmp(val,"rra\n") == 0 && (ft_lstsize(*stack_a) >  1 ))
		rra(stack_a);
	else if (ft_strcmp(val,"rrb\n") == 0 && (ft_lstsize(*stack_b) >  1))
		rrb(stack_b);
	else if (ft_strcmp(val,"rrr\n") == 0  && (ft_lstsize(*stack_a) >  1) && (ft_lstsize(*stack_b) >  1))
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
			if (ft_strcmp(val, "sa\n") == 0 && ft_lstsize(*stack_a) >  1 )
				sa(stack_a);
			else if (ft_strcmp(val, "sb\n") == 0 && ft_lstsize(*stack_b) >  1)
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
	
	if(!(stack_a))
		return 0;
	else 
		check_sort_actions(&stack_a,&stack_b);
	if (if_sort(stack_a))
		write(1,"KO\n", 3);
	else
		write(1,"OK\n", 3);
	return 0;
}
