
#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*head;

	head = malloc(sizeof(t_list));
	if (!head)
		return (NULL);
	head->content = content;
	head->next = NULL;
	return (head);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!*lst && new)
	{
		(*lst) = new;
		return ;
	}
	if (!new || !*lst)
		return ;
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

int main(int ac, char  **av)
{
	int i;
	int j;

	i = 0;
	j = 1;
	t_list *stack_a;
   	av = splitargs(ac,av);
	while(av[i])
	{
		printf("%s\n",av[i]);
		i++;
	}
	if (check_dig(ac,av) == 0)
		return 0;
	while (i < ac)
	{
		
		ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(av[i])));
		i++;
	}
	
	while(stack_a)
	{
		printf("%d\n", stack_a->content);
		stack_a = stack_a->next;
	} 
	
	return 0;
}
