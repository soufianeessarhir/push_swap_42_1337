/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_any.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 08:32:03 by sessarhi          #+#    #+#             */
/*   Updated: 2024/02/22 13:35:39 by sessarhi         ###   ########.fr       */
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
void reindex(t_list **stack_b)
{
	t_list *tmp;
	tmp = (*stack_b);
	while (*stack_b)
	{
		(*stack_b)->index = -1;
		(*stack_b)= (*stack_b)->next;
	}
	(*stack_b) = tmp;
}
int get_pos(t_list *stack, int nb)
{
    int pos;
	
	pos = 0;
    
    while (stack)
    {
        if (nb == stack->index)
            break;
        
        stack = stack->next;
        pos++;
    }
    
    return pos;
}

void _push(t_list **stack_a, t_list **stack_b, int max)
{
    int b_size = ft_lstsize(*stack_b);
    int pos = get_pos(*stack_b, max);

    if (pos <= b_size / 2)
    {
        while ((*stack_b)->index != max)
        {
            rb(stack_b);
        }
        pa(stack_a, stack_b);
    }
    else
    {
        while ((*stack_b)->index != max)
        {
            rrb(stack_b);
        }
        pa(stack_a, stack_b);
    }
}

void mov_to_a(t_list **stack_a,t_list **stack_b)
{
	int max;
	int befor_max; 

	while((*stack_b))
	{
		max = ft_lstsize(*stack_b);
		befor_max = max - 1;
		if (get_min_mov((*stack_b),max) <= get_min_mov((*stack_b),befor_max))
		{
			_push(stack_a,stack_b,ft_lstsize(*stack_b));
		}
		else
		{
			_push(stack_a,stack_b,ft_lstsize(*stack_b) -1);
			reindex(stack_b);
			indexing(stack_b);
			_push(stack_a,stack_b,ft_lstsize(*stack_b));
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
	else 
		a = (ft_lstsize(*stack_a) / 9);
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