/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_under_5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 04:19:37 by sessarhi          #+#    #+#             */
/*   Updated: 2024/02/16 04:35:53 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (min > tmp->next->content)
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
void push(t_list **stack_a,t_list **stack_b, int min,int flag)
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
	else if (min == 4 && flag == 0)
	{
		rra(stack_a);
		rra(stack_a);
		pb(stack_a,stack_b);
	}
	else if (min == (5 - flag))
	{
		rra(stack_a);
		pb(stack_a,stack_b);
	}	
}
void sort5(t_list **stack_a , t_list **stack_b)
{
	if (ft_lstsize(*stack_a) == 4)
	{
		push(stack_a,stack_b,find_min((*stack_a)),1);
		sort3(stack_a);
		pa(stack_a,stack_b);
	}
	else if (ft_lstsize(*stack_a) == 5)
	{
		push(stack_a,stack_b,find_min((*stack_a)),0);
		push(stack_a,stack_b,find_min((*stack_a)),1);
		sort3(stack_a);
		pa(stack_a,stack_b);
		pa(stack_a,stack_b);
	}
}