/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_any.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 08:32:03 by sessarhi          #+#    #+#             */
/*   Updated: 2024/02/20 20:37:52 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int get_min_mov(t_list *stack,int  max)
{
	t_list *tmp;
	int i;
	
	tmp = stack;
	i = 0;

	while(tmp)
	{
		if (max != tmp->index)
			i++;
		else
			break;
		tmp = tmp->next;
	}
	if (i <= (ft_lstsize(stack) / 2))
		return (i);
	return (ft_lstsize((stack)) - i);
}
void max_push(t_list **stack_a,t_list **stack_b,int max)
{
	if (get_pos((*stack_b),max) <= ft_lstsize((*stack_b)) / 2 )
	{
		while ((*stack_b)->index != max)
			rb(stack_b);
		pa(stack_a,stack_b);
	}
	else
	{
		while ((*stack_b)->index != max)
			rrb(stack_b);
		pa(stack_a,stack_b);
	}
}
void befor_max_push(t_list **stack_a,t_list **stack_b,int befor_max )
{
	if (get_pos((*stack_b),befor_max) <= ft_lstsize((*stack_b)) / 2 )
		{
			while ((*stack_b)->index != befor_max )
				rb(stack_b);
			pa(stack_a,stack_b);
		}
	else
		{
			while ((*stack_b)->index != befor_max)
				rrb(stack_b);
			pa(stack_a,stack_b);
		}
		return;
}
	
void _max(t_list *stack_b,int *max)
{
	
	t_list *tmp;
	
	*max = stack_b->index;
	tmp = stack_b;
	while (tmp->next)
	{
		if (*max < tmp->next->index)
			*max = tmp->next->index;
		tmp = tmp->next;
	}
	
}
void mov_to_a(t_list **stack_a,t_list **stack_b)
{
	int max;
	int befor_max;

	while((*stack_b))
	{
		
		_max(*stack_b,&max);
		befor_max = max - 1;
		if (get_min_mov((*stack_b),max) <= get_min_mov((*stack_b),befor_max))
		{
			max_push(stack_a,stack_b,max);
			befor_max_push(stack_a,stack_b,befor_max);
		}
		else
		{
			befor_max_push(stack_a,stack_b,befor_max);
			max_push(stack_a,stack_b,max);
			sa(stack_a);
		}
	}
}
void sort_any(t_list **stack_a, t_list **stack_b)
{
	int i;
	int a;
	int j;

	a = 0;
	if (ft_lstsize(*stack_a) <= 100)
		a = ft_lstsize(*stack_a) / 5;
	else if(ft_lstsize((*stack_a)) == 500)
		a = (ft_lstsize(*stack_a) / 9 );
	i = 0;
	j = a;
	
	while (*stack_a)
	{
		if ((*stack_a)->index <= j)
		{
			pb(stack_a,stack_b);
			i++;
			if ((*stack_b)->index > (j -  (a / 2)))
				rb(stack_b);
			if (i == j)
			{
				 j+= a;
			}
		}
		else 
			ra(stack_a);
	}
	mov_to_a(stack_a,stack_b);
}