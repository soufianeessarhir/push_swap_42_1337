/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 04:54:00 by sessarhi          #+#    #+#             */
/*   Updated: 2024/02/14 06:39:15 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void sort3(t_list **stack_a)
{
	int a;
	int b;
	int c;

	a = (*stack_a)->content;
	b = (*stack_a)->next->content;
	c = (*stack_a)->next->next->content;
	if (a > b && a < c)
		sa(stack_a);
	if (b < a && b > c)
	{
		sa (stack_a);
		rra(stack_a);
	}
	if (c > b && c < a)
	ra(stack_a);
	if (c < b && c > a)
	{
		sa (stack_a);
		ra (stack_a);
	}
	if (a > c && a < b)
		rra (stack_a);
}
int find_min(t_list *stack_a)
{
	int min;
	t_list *tmp;
	
	min = stack_a->content;
	tmp = stack_a;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			min = tmp->next->content;
		tmp = tmp->next;
	}
	if (min == stack_a->content)
		return 1;
	if (min == stack_a->next->content)
		return 2;
	if (min == stack_a->next->next->content)
		return 3;
	if (min == stack_a->next->next->next->content)
		return 4;
	if (min == stack_a->next->next->next->next->content)
		return 5;
	return (0);
}
void push(t_list **stack_a,t_list **stack_b, int min)
{
	if (min == 1)
		pb(stack_a,stack_b);
	else if (min == 2)
	{
		sa(stack_a);
		pb(stack_a,stack_b);
	}
	else if (min == 3)
	{
		ra(stack_a);
		sa(stack_a);
		pb(stack_a,stack_b);
	}
	else if (min == 4)
	{
		rra(stack_a);
		rra(stack_a);
		pb(stack_a,stack_b);
	}
	else if (min == 5)
	{
		rra(stack_a);
		pb(stack_a,stack_b);
	}	
}
void sort5(t_list **stack_a , t_list **stack_b)
{
	push(stack_a,stack_b,find_min((*stack_a)));
	push(stack_a,stack_b,find_min((*stack_a)));
	sort3(stack_a);
	pa(stack_a,stack_b);
	pa(stack_a,stack_b);
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
	if (ft_lstsize(stack_a) == 2)
	{
		if (stack_a->content > stack_a->next->content)
			sa (&stack_a);
	}
	if (ft_lstsize(stack_a) == 3)
		sort3(&stack_a);
	if (ft_lstsize(stack_a) == 5)
		sort5(&stack_a,&stack_b);
	while(stack_a)
	{
		printf("%d\n", stack_a->content);
		stack_a = stack_a->next;
	} 
	while(stack_b)
	{
		printf("%d\n", stack_b->content);
		stack_b = stack_b->next;
	} 
	return 0;
}
