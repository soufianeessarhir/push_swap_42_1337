/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 04:54:00 by sessarhi          #+#    #+#             */
/*   Updated: 2024/02/19 14:21:09 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_pos2(t_list *stack,int  max,int size)
{
	t_list *tmp;
	int i;
	int pos;
	int min_pos;
	
	tmp = (stack);
	i = 0;
	pos = -1;
	while(tmp)
	{
		if (max == tmp->index)
		{
			pos = i;
			break;
		}
		tmp = tmp->next;
		i++;	
	}
	if (pos <= size)
		min_pos = pos;
	else
		min_pos = size - pos;
	return min_pos;
}
void max_push(t_list **stack_a,t_list **stack_b,int max )
{
	if (get_pos((*stack_b),max) <= ft_lstsize((*stack_b)) )
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
void befor_max_push(t_list **stack_a,t_list **stack_b,int befor_max)
{
	if (get_pos((*stack_b),befor_max) <= ft_lstsize((*stack_b)) )
		{
			while ((*stack_b)->index != befor_max)
				rb(stack_b);
			pa(stack_a,stack_b);
		}
	else
		{
			while ((*stack_b)->index != befor_max)
				rrb(stack_b);
			pa(stack_a,stack_b);
		}
}
	
void _max(t_list *stack_b,int *max,int *befor_max)
{
	
	t_list *tmp;
	
	*max = stack_b->index;
	tmp = stack_b;
	while (tmp->next)
	{
		if (*max < tmp->next->index)
		{
			*befor_max = *max;
			*max = tmp->next->index;
		}
		tmp = tmp->next;
	}
}
void mov_to_a(t_list **stack_b,t_list **stack_a)
{
	int max;
	int befor_max;
	
	while((*stack_b))
	{
		 _max(*stack_b,&max,&befor_max) ;
		if (get_pos2((*stack_b),max,ft_lstsize((*stack_b))) <= get_pos2((*stack_b),befor_max,ft_lstsize((*stack_b))))
		{
			max_push((stack_a),(stack_b),max);
			befor_max_push((stack_a),(stack_b),befor_max);
		}
		else
		{
			befor_max_push((stack_a),(stack_b),befor_max);
			max_push((stack_a),(stack_b),max);
			sa(stack_a);
		}
	}
}
void sort_100(t_list **stack_a, t_list **stack_b)
{
	int i;
	int r_min;

	i = 0;
	r_min = 0;
	
	while (*stack_a)
	{
		if ((*stack_a)->index >= r_min && (*stack_a)->index < r_min + 20)
		{
			pb(stack_a,stack_b);
			i++;
			if ((*stack_b)->index > ((r_min +  10)))
				rb(stack_b);		
			if (i == 20)
			{
				i = 0;
				r_min = r_min + 20;
			}
		}
		else 
			ra(stack_a);
	}
	mov_to_a(stack_b,stack_b);
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
	sort_100(&stack_a,&stack_b);
	// if (ft_lstsize(stack_a) == 5 || ft_lstsize(stack_a) == 4)
	// 	sort5(&stack_a,&stack_b);
	// else
	// sort_all(&stack_a,&stack_b);
	// while(stack_a)
	// {
	// 	printf("%d ===> index = %d\n" , stack_a->content, stack_a->index);
	// 	stack_a = stack_a->next;
	// } 
	// if (ft_lstsize(stack_a) == 2)
	// {
	// 	if (stack_a->content > stack_a->next->content)
	// 		sa (&stack_a);
	// }
	// if (ft_lstsize(stack_a) == 3)
	// 	sort3(&stack_a);
	// while(stack_b)
	// {
	// 	printf("%d\n", stack_b->content);
	// 	stack_b = stack_b->next;
	// } 
	return 0;
}
